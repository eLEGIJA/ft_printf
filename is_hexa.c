/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:28:46 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:08:08 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_in_put_part_hexa(char *hexa, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += treat_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	char_count += ft_putstrprec(hexa, ft_strlen(hexa));
	return (char_count);
}

static int		ft_put_part_hexa(char *hexa, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += treat_width(flags.width, 0, 0);
	}
	else
		char_count += treat_width(flags.width,
		ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_hexa(hexa, flags);
	return (char_count);
}

int				ft_hexa(unsigned int ui, int lower, t_flag flags)
{
	char	*hexa;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)(4294967295 + 1
				+ ui);
	if (flags.dot == 0 && ui == 0)
	{
		char_count += treat_width(flags.width, 0, 0);
		return (char_count);
	}
	hexa = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hexa = ft_str_tolower(hexa);
	char_count += ft_put_part_hexa(hexa, flags);
	free(hexa);
	return (char_count);
}
