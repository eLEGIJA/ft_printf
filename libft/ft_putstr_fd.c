/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 23:08:19 by msafflow          #+#    #+#             */
/*   Updated: 2020/05/13 17:07:14 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (fd < 0)
		return ;
	if ((char*)str == NULL)
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
