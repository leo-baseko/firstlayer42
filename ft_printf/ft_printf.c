/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:07:57 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/08 19:18:07 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putnbr_base(unsigned int nb, char *base, int len);
int	ft_putchar(int c);

static int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static int	ft_percentchar(char a, va_list b)
{
	int	c;

	c = 0;
	if (a == 'c')
		return (ft_putchar(va_arg(b, int)));
	if (a == 's')
		return (ft_putstr(va_arg(b, char *)));
	if (a == 'd')
	{
		c = va_arg(b, int);
		if (c < 0)
			ft_putchar(-c);
		return (ft_putnbr_base(c, "0123456789", 10));
	}
	if (a == 'x')
		return (ft_putnbr_base(va_arg(b, int), "0123456789abcdef", 16));
	if (a == 'X')
		return (ft_putnbr_base(va_arg(b, int), "0123456789ABCDEF", 16));
	if (a == '%')
		write(1, "%", 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	j;
	int				i;
	va_list			arg;

	j = 0;
	i = 0;
	va_start(arg, format);
	while (format[j])
	{
		while (format[j] != '%' && format[j] != '\0')
		{
			write(1, &format[j], 1);
			j++;
		}
		if (format[j++] == '%' && format[j] != '\0')
			i += ft_percentchar(format[j], arg);
		if (format[j])
			j++;
	}
	va_end(arg);
	return (i);
}

int	main(void)
{
	// printf("<PRINTF> yo les amis %d %s %o %x %c %X %%\n", 9, "coucou", 10, 254, 'a', 254);
	// ft_printf("c : %c\nd : %d\ns : %s\nx : %x\nX : %X\npourcent : %%\n", 'a', -42, "coucouuuuu", 254, 254);
	ft_printf("c : %c", 'a');
	ft_printf("d : %d", 9999);
	ft_printf("s : %s", "i");
	ft_printf("x : %x", 254);
	ft_printf("X : %X", 254);
	ft_printf("pourcent : %%");
	// printf("c : %c\n", 'a');
	// printf("d : %d\n", -9999);
	return (0);
}
