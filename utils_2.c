#include "ft_printf.h"

void	ft_putnbr(int num, int *len)
{
	char	c;

	if (num == -2147483648)
		ft_putstr("-2147483648", len);
	else if (num < 0)
	{
		num = -num;
		ft_putchar('-', len);
		ft_putnbr(num, len);
	}
	else if (num > 9)
	{
		ft_putnbr(num / 10, len);
		ft_putnbr(num % 10, len);
	}
	else
	{
		c = num + '0';
		ft_putchar(c, len);
	}
}

void	ft_putnbr_u(unsigned int num, int *len)
{
	char	c;

	if (num > 9)
	{
		ft_putnbr_u(num / 10, len);
		ft_putnbr_u(num % 10, len);
	}
	else
	{
		c = num + '0';
		ft_putchar(c, len);
	}
}
