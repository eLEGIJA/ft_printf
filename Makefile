# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/08 04:04:32 by smatha            #+#    #+#              #
#    Updated: 2020/07/31 09:10:26 by msafflow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

SRCS =	ft_printf.c ft_parser.c treat_width.c ft_u_itoa.c ft_ull_base.c \
		ft_putstrprec.c is_string.c is_char.c is_pointer.c is_int.c is_u.c\
		is_percent.c is_hexa.c ft_flags.c

SRC_OBJECTS = $(SRCS:.c=.o)

HEADERS = ft_printf.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: MKLIB $(NAME).a

MKLIB:
	@make -C $(LIBFT)
$(NAME).a: $(LIBFT)/$(LIBFT).a $(SRC_OBJECTS)
	@cp $(LIBFT)/$(LIBFT).a ./$(NAME)
	@ar rcs $(NAME) $(SRC_OBJECTS)
	
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
	
clean:
	@/bin/rm -rf $(SRC_OBJECTS)
	@make -C $(LIBFT) clean
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re:
	@make -C $(LIBFT) fclean
	@make fclean
	@make all

