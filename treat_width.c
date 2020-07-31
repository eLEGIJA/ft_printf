/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:26:54 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/29 09:39:15 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		treat_width(int width, int minus, int has_zero)
{
	int		char_count;

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
