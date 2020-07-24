/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatha <smatha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:01:02 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 17:03:05 by smatha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_flag
{
	int				format;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flag;

char	*ft_strdup(const char *s1);
int		ft_printf(const char *input, ...);
int		ft_putstrprec(char *str, int prec);
int		ft_putchar(int c);

#endif