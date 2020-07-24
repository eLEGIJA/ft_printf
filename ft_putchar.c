
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 15:37:44 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 17:13:51 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}


int		ft_putstrprec(char *str, int prec)
{
	int		char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
	{
		ft_putchar_fd(str[char_count], 1);
		char_count++;
	}
	return (char_count);
}

