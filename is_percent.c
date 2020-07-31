/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 13:14:39 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:08:07 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_percent(t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrprec("%", 1);
	char_count += treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrprec("%", 1);
	return (char_count);
}
