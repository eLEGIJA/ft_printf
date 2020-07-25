/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 15:10:46 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:09 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_dot_uint(char *u_int, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_width(flags.dot - 1, ft_strlen(u_int) - 1, 1);
	char_count += strprecision(u_int, ft_strlen(u_int));
	return (char_count);
}

static int	ft_width_uint(char *u_int, t_flag flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_dot_uint(u_int, flags);
	if (flags.dot >= 0 && (int)flags.dot < ft_strlen(u_int))
		flags.dot = ft_strlen(u_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_width(flags.width, 0, 0);
	}
	else
		char_count += ft_width(flags.width, ft_strlen(u_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_dot_uint(u_int, flags);
	return (char_count);
}

int			is_uint(unsigned int ui, t_flag flags)
{
	char	*u_int;
	int		char_count;

	char_count = 0;
	ui = (unsigned int)ui;
	if (flags.dot == 0 && ui == 0)
	{
		char_count += ft_width(flags.width, 0, 0);
		return (char_count);
	}
	u_int = uconvert(ui, 10);
	char_count += ft_width_uint(u_int, flags);
	free(u_int);
	return (char_count);
}
