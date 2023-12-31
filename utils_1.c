#include "ft_printf.h"

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

void	ft_puthex(int num, int *len)
{
	char	*str;

	str = ft_strdup("0123456789abcdef");
	if (num > 15)
		ft_puthex(num / 16, len);
	ft_putnbr_u(num, len);
	free(str);
}

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

// int main()
// {
// 	unsigned int i = 3147483648;
// 	int len = 0;
// 	ft_putnbr_u(i, &len);
// 	write (1, "\n", 1);
// }
