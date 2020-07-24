/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:42:10 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 16:34:19 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag		init_flags(void)
{
	t_flag	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.format = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int		ft_width(int width, int minus, int has_zero)
{
	int	char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

int		strprecision(char *str, int precision)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < precision)
		ft_putchar(str[char_count++]);
	return (char_count);
}

int			is_char(int c, t_flag flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	char_count = ft_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}

static int		is_flag_dot(char *str, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int				is_string(char *str, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += is_flag_dot(str, flags);
	if (flags.dot >= 0)
		char_count += ft_width(flags.width, flags.dot, 0);
	else
		char_count += ft_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		char_count += is_flag_dot(str, flags);
	return (char_count);
}

static int	int_minus(char *str, int save_i, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (save_i < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		char_count += ft_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	char_count += strprecision(str, ft_strlen(str));
	return (char_count);
}

static int	int_counter(char *d_i, int save_i, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += int_minus(d_i, save_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		char_count += int_minus(d_i, save_i, flags);
	return (char_count);
}

int			is_int(int i, t_flag flags)
{
	char	*str;
	int		save_i;
	int		char_count;

	save_i = i;
	char_count = 0;
	if (flags.dot == 0 && i == 0)
	{
		char_count += ft_width(flags.width, 0, 0);
		return (char_count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			strprecision("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		char_count++;
	}
	str = ft_itoa(i);
	char_count += int_counter(str, save_i, flags);
	free(str);
	return (char_count);
}

int			format_len(int c, t_flag flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = is_char(va_arg(args, int), flags);
	else if (c == 's')
		char_count = is_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = is_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = is_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += is_uint((unsigned int)va_arg(args, unsigned int),flags);
	else if (c == 'x')
		char_count += is_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += is_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += is_percent(flags);
	return (char_count);
}

char		*convert(unsigned int num, int base) 
{ 
    static char	*representation;
    char		*ptr;
	int			len;

	*representation = "0123456789ABCDEF";
	len = ft_nbrlen(num, base);
    if(!(ptr = (char)malloc(len + 1)))
		return (NULL);
	ptr[len+1]= '\0';
    while(num != 0);
    { 
        *--ptr = representation[num%base]; 
        num /= base; 
    } 
    return(ptr); 
}

int         is_format(char c)
{
    const char  *formats;

    formats = "cspdiux";
    if (ft_strchr(formats, c))
        return (1);
    else
        return (0);
}

int         is_flag(char c)
{
    const char  *flags;

    flags = "-0.*";
    if (ft_strchr(flags, c))
        return (1);
    else
        return (0);
}

int         flag_parser(const char *save, int i, t_flag *flags, va_list args)
{
    while (save[i])
	{
		if (!ft_isdigit(save[i]) && !is_flag(save[i])
		&& !is_format(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = flag_dot(save, i, flags, args);
		if (save[i] == '-')
			*flags = flag_minus(*flags);
		if (save[i] == '*')
			*flags = flag_width_star(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = flag_width(save[i], *flags);
		if (if_format(save[i]))
		{
			flags->format = save[i];
			break ;
		}
		i++;
	}
    return (i);
}

int         saver(const char *save, va_list args)
{
    int         i;
    t_flag      flags;
    int			char_count;

    i = 0;
    char_count = 0;
    flags = init_flags();
    while (save[i])
    {
		if (save[i] == '%' && save[i + 1])
        {
            i = flag_parser(save, ++i, &flags, args);
            if (is_format(save[i]))
				char_count += format_len((char)flags.format, flags, args);
            else if (save[i])
				char_count += ft_putchar(save[i]);
        }
        else if (save[i] != '%')
			char_count += ft_putchar(save[i]);
		i++;
    }
    return (char_count);
}

int			ft_printf(const char *input, ...)
{
	const char	*save;
	va_list		args;
	int			char_count;

	save = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count += saver(save, args);
	va_end(args);
	free((char *)save);
	return (char_count);
}
