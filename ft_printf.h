#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
char	*ft_strdup(const char *s1);
void	arg_checking(const char *str, va_list args, int *len);
void	ft_putchar(int c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_puthex(int num, int *len);
void	ft_putnbr(int num, int *len);
void	ft_putnbr_u(unsigned int num, int *len);

#endif
