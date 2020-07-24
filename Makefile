NAME = libftprintf.a

SRCS =	ft_printf.c ft_flags.c ft_isdigit.c ft_nbrlen.c ft_putchar.c \
		ft_strchr.c ft_strdup.c ft_tolower.c

SRC_OBJECTS = $(SRCS:.c=.o)

HEADERS = libftprintf.h

FLAGS = -Wall -Wextra -Werror -g

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC_OBJECTS)
	@ar rc $(NAME) $(SRC_OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME) generated"

%.o: %.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@
	@echo "$< compiled"

clean:
	@/bin/rm -f $(OBJECTS)
	@echo "All objects removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all

