/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 05:47:32 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:08:05 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_in_put_part_uint(char *u_int, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += treat_width(flags.dot - 1, ft_strlen(u_int) - 1, 1);
	char_count += ft_putstrprec(u_int, ft_strlen(u_int));
	return (char_count);
}

static int	ft_put_part_uint(char *u_int, t_flag flags)
{
	int		char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_in_put_part_uint(u_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(u_int))
		flags.dot = ft_strlen(u_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += treat_width(flags.width, 0, 0);
	}
	else
		char_count += treat_width(flags.width,
		ft_strlen(u_int), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_uint(u_int, flags);
	return (char_count);
}

int			ft_u(unsigned int unsi, t_flag flags)
{
	char	*u_int;
	int		char_count;

	char_count = 0;
	unsi = (unsigned int)(4294967295 + 1
				+ unsi);
	if (flags.dot == 0 && unsi == 0)
	{
		char_count += treat_width(flags.width, 0, 0);
		return (char_count);
	}
	u_int = ft_u_itoa(unsi);
	char_count += ft_put_part_uint(u_int, flags);
	free(u_int);
	return (char_count);
}
