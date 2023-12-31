#include "ft_printf.h"

void	arg_checking(const char *str, va_list args, int *len)
{
	if (*str == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (*str == 'p')
		ft_puthex((unsigned long)va_arg(args, void *), len);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (*str == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (*str == 'x' || *str == 'X')
		ft_puthex(va_arg(args, unsigned int), len);
	else
		ft_putchar('%', len);
}
