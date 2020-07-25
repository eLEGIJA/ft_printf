/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:01:02 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/25 16:19:18 by msafflow         ###   ########.fr       */
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

int			ft_width(int width, int minus, int has_zero);
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
int			ft_strlen(char *str);
int			strprecision(char *str, int precision);
char		*convert(int num, int base);
int			is_hex(unsigned int ui, int lower, t_flag flags);
int			is_percent(t_flag flags);
int			is_uint(unsigned int ui, t_flag flags);
int			is_pointer(unsigned long long ullong, t_flag flags);
char		*ft_strtolower(char *str);
#endif
