/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:18:19 by smatha            #+#    #+#             */
/*   Updated: 2020/07/31 09:08:07 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_minus_di(t_flag *print, long long num, int *i, char *s)
{
	if (num < 0 && print->zero == 0)
		write(1, "-", 1);
	while ((*i)++ < 0)
		write(1, "0", 1);
	if (print->dot != 0 || num != 0)
		ft_putstr_fd(s, 1);
}

static void		ft_form_di(t_flag *print)
{
	if (print->width < 0)
	{
		print->width = ft_abs(print->width);
		print->minus = 1;
		print->zero = 0;
	}
	if (print->dot > -1)
		print->zero = 0;
}

static void		ft_print_flag_di(t_flag *print, int *res, long long num)
{
	if (print->zero == 1 && num != 0)
	{
		if (num < 0)
			write(1, "-", 1);
	}
	while (*res < print->width)
	{
		if (print->zero == 1 && print->dot != 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		(*res)++;
	}
}

char			*ft_lltoa_u(long long int n)
{
	size_t		i;
	long long	j;
	char		*str;

	j = n;
	i = (j == 0) ? 1 : 0;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	j = n;
	j = (j < 0) ? -j : j;
	while (i-- > 0)
	{
		str[i] = j % 10 + '0';
		j = j / 10;
	}
	return (str);
}

int				ft_int(int num, t_flag *print)
{
	int		res;
	char	*s;
	int		i;

	ft_form_di(print);
	if (!(s = ft_lltoa_u((long long)num)))
		return (-1);
	i = ft_strlen(s);
	i = (i == print->dot) ? i : i - print->dot;
	res = (i < 0) ? print->dot : (int)ft_strlen(s);
	res = (num < 0) ? res + 1 : res;
	if (print->dot == 0 && num == 0)
		res = 0;
	if (print->minus == 1)
		ft_minus_di(print, (long long)num, &i, s);
	ft_print_flag_di(print, &res, (long long)num);
	if (print->minus == 0)
		ft_minus_di(print, (long long)num, &i, s);
	free(s);
	return (res);
}
