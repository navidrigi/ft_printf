#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			arg_checking(str[i], args, &len);
		}
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	char *str = "Hello, world!";
// 	int num = 123;
// 	int ret1 = printf("%s %x %p\n", str, num, str);
// 	int ret2 = ft_printf("%s %x %p\n", str, num, str);
// 	printf("printf_1: %d\n", ret1);
// 	printf("printf_2: %d\n", ret2);
// 	return (0);
// }
