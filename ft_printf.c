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
			arg_checking(str, args, &len);
		}
		else
			len += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
