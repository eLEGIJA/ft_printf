/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:41:18 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:11 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		is_flag_dot(char *str, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += ft_width(flags.dot, ft_strlen(str), 0);
		char_count += strprecision(str, flags.dot);
	}
	else
	{
		char_count += strprecision(str, ft_strlen(str));
	}
	return (char_count);
}

int				is_string(char *str, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (int)flags.dot > ft_strlen(str))
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