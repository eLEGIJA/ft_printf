# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msafflow <elegija4mlg@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/13 17:59:12 by msafflow          #+#    #+#              #
#    Updated: 2020/05/13 17:59:12 by msafflow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC_OBJECTS = $(patsubst %.c,%.o,$(SRC))
BNS_OBJECTS = $(patsubst %.c,%.o,$(BNS))

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	@ar rc $(NAME) $(SRC_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) generated"

# $@ -Имя цели обрабатываемого правила
# $< Имя первой зависимости обрабатываемого правила
%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$@ added"
clean:
	@/bin/rm -rf $(SRC_OBJECTS) $(BNS_OBJECTS)
	@echo "All objects removed"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "$(NAME) removed"

re: fclean all

bonus: $(BNS_OBJECTS)
ifeq ($(shell test -f $(NAME) && ar t $(NAME) | grep lst),)
	@ar rc $(NAME) $(BNS_OBJECTS)
	@ranlib $(NAME)
	@echo "Bonus added"
endif
