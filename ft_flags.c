/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 08:14:23 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:05:51 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag		ft_flag_minus(t_flag flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flag		ft_flag_digit(char c, t_flag flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

t_flag		ft_flag_width(va_list args, t_flag flags)
{
	flags.star = 1;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int			ft_flag_dot(const char *copy, int start,
			t_flag *flags, va_list args)
{
	int		i;

	i = start;
	i++;
	if (copy[i] == '*')
	{
		flags->dot = va_arg(args, int);
		i++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(copy[i]))
			flags->dot = (flags->dot * 10) + (copy[i++] - '0');
	}
	return (i);
}
