/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:40:29 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 18:33:50 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
