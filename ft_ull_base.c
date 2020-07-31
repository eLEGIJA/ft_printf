/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:16:59 by smatha            #+#    #+#             */
/*   Updated: 2020/07/29 09:39:13 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}
