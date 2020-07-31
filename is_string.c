/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:27:05 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/31 09:08:05 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_put_part_int(char *str, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.dot >= 0)
	{
		char_count += treat_width(flags.dot, ft_strlen(str), 0);
		char_count += ft_putstrprec(str, flags.dot);
	}
	else
	{
		char_count += ft_putstrprec(str, ft_strlen(str));
	}
	return (char_count);
}

int				ft_string(char *str, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		char_count += ft_put_part_int(str, flags);
	if (flags.dot >= 0)
		char_count += treat_width(flags.width, flags.dot, flags.zero);
	else
		char_count += treat_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		char_count += ft_put_part_int(str, flags);
	return (char_count);
}
