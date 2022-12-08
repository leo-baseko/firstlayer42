/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:07:57 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/08 15:54:11 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putnbr_base(unsigned int nb, char *base, int len);

static void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

static void	ft_percentchar(char a, va_list b)
{
	if (a == 'c')
	{
		int	c;
		c = va_arg(b, int);
		write(1, &c, 1);
	}
	if (a == 'd')
	{
		int	c;
		c = va_arg(b, int);
		if (c < 0)
		{
			c = -c;
			write(1, "-", 1);
		}
		ft_putnbr_base(c, "0123456789", 10);
	}
	if (a == 'o')
	{
		int	c;
		c = va_arg(b, int);
		ft_putnbr_base((int)c, "01234567", 8);
	}
	if (a == 's')
	{	
		char	*c;
		c = va_arg(b, char *);
		ft_putstr(c);
	}
	if (a == 'x') 
	{	
		int c;
		c = va_arg(b, int);
		ft_putnbr_base(c, "0123456789abcdef", 16);
	}
	if (a == 'X')
	{	
		int c;
		c = va_arg(b, int);
		ft_putnbr_base(c, "0123456789ABCDEF", 16);
	}
	if (a == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	j;
	size_t			i;
	va_list			arg;

	j = 0;
	i = 0;
	va_start(arg, format);
	while (format[j] != '\0')
	{
		while (format[j] != '%' && format[j] != '\0')
		{
			write(1, &format[j], 1);
			j++;
		}
		if (format[j++] == '%')
			ft_percentchar(format[j], arg);
		j++;
	}
	va_end(arg);
	return (i);
}

int	main(void)
{
	// printf("<PRINTF> yo les amis %d %s %o %x %c %X %%\n", 9, "coucou", 10, 254, 'a', 254);
	ft_printf("c : %c\nd : %d\no : %o\ns : %s\nx : %x\nX : %X\npourcent : %%\n", 'a', -42, 12, "coucou", 254, 254);
	// myprintf("d : %d\n", 9999);
	// myprintf("s : %s\n", "Salut");
	// myprintf("o : %o\n", 10);
	// myprintf("x : %x\n", 254);
	// myprintf("X : %X\n", 254);
	// myprintf("pourcent : %%\n");
	// printf("c : %c\n", 'a');
	// printf("d : %d\n", -9999);
	return (0);
}
