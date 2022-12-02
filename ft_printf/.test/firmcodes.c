// http://www.firmcodes.com/write-printf-function-c/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

static void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	ft_percentchar(char a, va_list b)
{
	if (a == 'c')
	{
		b += va_arg(b, int);
		write(1, &b, 1);
	}
	if (a == 'd')
	{
		int	c;
		c = (int)b;
		if (c < 0)
		{
			c = -c;
			write(1, "-", 1);
		}
		ft_putnbr_base(c, "0123456789");
	}
	if (a == 'o')
	{
		b += va_arg(b, unsigned int);
		ft_putnbr_base((int)b, "01234567");
	}
	if (a == 's')
		ft_putstr((char *)b);
	if (a == 'x') 
		ft_putnbr_base((int)b, "0123456789abcdef");
	if (a == 'X')
		ft_putnbr_base((int)b, "0123456789ABCDEF");
	if (a == '%')
		write(1, "%", 1);
}

void	myprintf(char *format, ...)
{
	unsigned int	j;
	va_list			arg;
	size_t			i;

	j = 0;
	i = 0;
	va_start(arg, format);
	while (format[j] != '\0')
	{
		while (format[j] != '%')
		{
			write(1, &format[j], 1);
			j++;
		}
		if (format[j] == '%')
			ft_percentchar(format[j + 1], arg);
		j++;
	}
	va_end(arg);
}

int	main(void)
{
	printf("<PRINTF> yo les amis %d %s %o %x %c %X %%\n", 9, "coucou", 10, 254, 'a', 254);
	myprintf("<MYPRINTF> yo les amis %d %s %o %x %c %X %%\n", 9 , "coucou", 10, 254, 'a', 254);
	//myprintf("%H");
	return (0);
}
