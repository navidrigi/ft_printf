#include "ft_printf.h"

void	arg_checking(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_puthex((unsigned long)va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), len);
	else
		ft_putchar('%', len);
}
