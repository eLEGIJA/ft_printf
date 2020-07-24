/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:42:10 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 17:23:55 by msafflow         ###   ########.fr       */
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
