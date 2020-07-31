/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:25:10 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/31 09:08:09 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_char(char c, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	char_count = treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}
