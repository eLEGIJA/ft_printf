/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:03:31 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:17 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_hex_minus(char *hex, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	char_count += strprecision(hex, ft_strlen(hex));
	return (char_count);
}

static int		ft_width_hex(char *hex, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_hex_minus(hex, flags);
	if (flags.dot >= 0 && (int)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_width(flags.width, 0, 0);
	}
	else
		char_count += ft_width(flags.width,
		ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		char_count += ft_hex_minus(hex, flags);
	return (char_count);
}

int				is_hex(unsigned int ui, int lower, t_flag flags)
{
	char	*hex;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)ui;
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_width(flags.width, 0, 0);
		return (char_count);
	}
	hex = uconvert(ui, 16);
	if (lower == 1)
		hex = ft_strtolower(hex);
	char_count += ft_width_hex(hex, flags);
	free(hex);
	return (char_count);
}