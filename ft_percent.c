/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:11:31 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:14 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_percent(t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += strprecision("%", 1);
	char_count += ft_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += strprecision("%", 1);
	return (char_count);
}
