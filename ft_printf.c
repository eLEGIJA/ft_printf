/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 08:58:06 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/31 08:58:38 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_abs(int i)
{
	return (i > 0) ? i : -i;
}

t_flag		ft_init_flag(void)
{
	t_flag		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int			ft_flag_parse(const char *copy, int i, t_flag *flags, va_list args)
{
	while (copy[i])
	{
		if (!ft_isdigit(copy[i]) && !is_type(copy[i]) && !is_flag(copy[i]))
			break ;
		if (copy[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (copy[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (copy[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (copy[i] == '.')
			i = ft_flag_dot(copy, i, flags, args);
		if (ft_isdigit(copy[i]))
			*flags = ft_flag_digit(copy[i], *flags);
		if (is_type(copy[i]))
		{
			flags->type = copy[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_parse_copy(const char *copy, va_list args)
{
	int			i;
	t_flag		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flag();
		if (!copy[i])
			break ;
		else if (copy[i] == '%' && copy[i + 1])
		{
			i = ft_flag_parse(copy, ++i, &flags, args);
			if (is_type(copy[i]))
				char_count += ft_parser((char)flags.type, flags, args);
			else if (copy[i])
				char_count += ft_putchar(copy[i]);
		}
		else if (copy[i] != '%')
			char_count += ft_putchar(copy[i]);
		i++;
	}
	return (char_count);
}

int			ft_printf(const char *str, ...)
{
	const char	*copy;
	va_list		args;
	int			char_count;

	if (!(copy = ft_strdup(str)))
		return (0);
	char_count = 0;
	va_start(args, str);
	char_count += ft_parse_copy(copy, args);
	va_end(args);
	free((char*)copy);
	return (char_count);
}
