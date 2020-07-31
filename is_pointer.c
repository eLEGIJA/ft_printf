/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:16:59 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:08:06 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_str_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static int	ft_in_put_part_pointer(char *pointer, t_flag flags)
{
	int char_count;

	char_count = 0;
	char_count += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		char_count += treat_width(flags.dot, ft_strlen(pointer), 1);
		char_count += ft_putstrprec(pointer, flags.dot);
	}
	else
		char_count += ft_putstrprec(pointer, ft_strlen(pointer));
	return (char_count);
}

int			ft_pointer(unsigned long long ull, t_flag flags)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		if (flags.minus == 0)
			char_count += treat_width(flags.width - 2, 0, flags.zero);
		char_count += ft_putstrprec("0x", 2);
		if (flags.minus == 1)
			char_count += treat_width(flags.width - 2, 0, flags.zero);
		return (char_count);
	}
	pointer = ft_ull_base(ull, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)flags.dot < ft_strlen(pointer))
		flags.dot = ft_strlen(pointer);
	if (flags.minus == 1)
		char_count += ft_in_put_part_pointer(pointer, flags);
	char_count += treat_width(flags.width, ft_strlen(pointer) + 2, 0);
	if (flags.minus == 0)
		char_count += ft_in_put_part_pointer(pointer, flags);
	free(pointer);
	return (char_count);
}
