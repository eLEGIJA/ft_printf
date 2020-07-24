/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatha <smatha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 12:01:02 by msafflow          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/07/24 17:03:05 by smatha           ###   ########.fr       */
=======
/*   Updated: 2020/07/24 17:14:29 by msafflow         ###   ########.fr       */
>>>>>>> 5d73b5124e7e0165a427f913b4eed46154b522ac
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
}	                t_flag;

char		*ft_strdup(const char *s1);
int			ft_printf(const char *input, ...);
int			ft_putstrprec(char *str, int prec);
int			ft_putchar(int c);
t_flag		flag_minus(t_flag flags);
t_flag		flag_width_star(char c, t_flag flags);
int			flag_dot(const char *save, int start, t_flag *flags, va_list args);
t_flag		flag_width(va_list args, t_flag flags);
int			ft_tolower(int c);
char		*ft_strdup(char *src);
int     	ft_printf(const char *input, ...);
char		*ft_strchr(const char *s, int c);
int			ft_putchar(char c);
int			ft_nbrlen(int nbr, int base);
int			ft_isdigit(int c);
int			is_int(int i, t_flag flags);
int				is_string(char *str, t_flag flags);

#endif
