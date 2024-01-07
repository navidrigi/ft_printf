#include "ft_printf.h"

void	arg_checking(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'p')
		ft_putptr(va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), len);
	else
		ft_putchar('%', len);
}

void	ft_putchar(int c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], len);
		i++;
	}
}

void	ft_putptr(void *ptr, int *len)
{
	int				i;
	unsigned long	num;
	const char		*str = "0123456789abcdef";
	char			buffer[20];

	i = 18;
	num = (unsigned long)ptr;
	buffer[19] = '\0';
	while (num != 0)
	{
		buffer[i] = str[num % 16];
		num /= 16;
		i--;
	}
	buffer[i] = 'x';
	i--;
	buffer[i] = '0';
	ft_putstr(&buffer[i], len);
}

void	ft_puthex(int num, int *len)
{
	const char	*str = "0123456789abcdef";

	if (num > 15)
		ft_puthex(num / 16, len);
	ft_putchar(str[num % 16], len);
}
