/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 09:26:35 by msafflow          #+#    #+#             */
/*   Updated: 2020/07/31 09:10:43 by msafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flag
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flag;

int					ft_printf(const char *str, ...);
int					ft_abs(int i);
int					is_type(int c);
int					is_flag(int c);
int					ft_parser(int c, t_flag flags, va_list args);
int					treat_width(int width, int minus, int has_zero);
int					ft_putstrprec(char *str, int prec);
int					is_char(char c, t_flag flags);
int					ft_string(char *str, t_flag flags);
int					ft_int(int num, t_flag *print);
char				*ft_lltoa_u(long long int n);
int					ft_percent(t_flag flags);
int					ft_hexa(unsigned int ui, int lower, t_flag flags);
int					ft_u(unsigned int unsi, t_flag flags);
int					ft_flag_dot(const char *save, int start,
					t_flag *flags, va_list args);
int					ft_putchar(int c);
int					ft_pointer(unsigned long long pointer, t_flag flags);

char				*ft_ull_base(unsigned long long ull, int base);
char				*ft_u_itoa(unsigned int n);
char				*ft_str_tolower(char *str);

t_flag				ft_flag_minus(t_flag flags);
t_flag				ft_flag_width(va_list args, t_flag flags);
t_flag				ft_flag_digit(char c, t_flag flags);

#endif
