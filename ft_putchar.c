

#include "libftprintf.h"

int		ft_putstrprec(char *str, int prec)
{
	int		char_count;

	char_count = 0;
	while (str[char_count] && char_count < prec)
	{
		ft_putchar_fd(str[char_count], 1);
		char_count++;
	}
	return (char_count);
}

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}