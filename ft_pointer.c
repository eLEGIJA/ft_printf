/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:17:36 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:13 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_dot_pointer(char *pointer, t_flag flags)
{
	int char_count;

	char_count = 0;
	char_count += strprecision("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += ft_width(flags.dot, ft_strlen(pointer), 1);
		char_count += strprecision(pointer, flags.dot);
	}
	else
		char_count += strprecision(pointer, ft_strlen(pointer));
	return (char_count);
}

int			is_pointer(unsigned long long ullong, t_flag flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ullong == 0 && flags.dot == 0)
	{
		char_count += strprecision("0x", 2);
		return (char_count += ft_width(flags.width, 0, 1));
	}
	pointer = ullconvert(ullong, 16);
	pointer = ft_strtolower(pointer);
	if ((int)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_dot_pointer(pointer, flags);
	char_count += ft_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_dot_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
