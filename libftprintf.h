/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:01:02 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/24 18:02:00 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}	                t_flag;

int			ft_putchar(int c);
char		*ft_strdup(const char *src);
int			ft_printf(const char *input, ...);
t_flag		flag_minus(t_flag flags);
t_flag		flag_width_star(char c, t_flag flags);
int			flag_dot(const char *save, int start, t_flag *flags, va_list args);
t_flag		flag_width(va_list args, t_flag flags);
int			ft_tolower(int c);
int     	ft_printf(const char *input, ...);
char		*ft_strchr(const char *s, int c);
int			ft_nbrlen(int nbr, int base);
int			ft_isdigit(int c);
int			is_int(int i, t_flag flags);
int			is_string(char *str, t_flag flags);
int         saver(const char *save, va_list args);

#endif
