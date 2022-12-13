/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:07:57 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/13 16:27:05 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (a == 'p')
		return (ft_pointer_tohex(va_arg(b, void *), "0123456789abcdef", 16));
	if (a == 'd')
	{
		c = va_arg(b, int);
		if (c < 0)
			ft_putchar(-c);
		return (ft_putnbr_base(c, "0123456789", 10));
	}
	if (a == 'i')
	{
		c = va_arg(b, int);
		if (c < 0)
			ft_putchar(-c);
		return (ft_putnbr_base(c, "0123456789", 10));
	}
	if (a == 'u')
		return (ft_putnbr_base(va_arg(b, unsigned int), "0123456789", 10));
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
			write(1, &format[j++], 1);
		if (format[j] == '%' && format[j++] != '\0')
			i += ft_percentchar(format[j], arg);
		if (format[j])
			j++;
	}
	va_end(arg);
	return (i);
}

// #include <stdio.h>
// #include <stdarg.h>
// #include <unistd.h>
// int	main(void)
// {
// 	ft_printf("c : %c\n\t\v\f\r", 'a');
// 	ft_printf("d : %d\n", 9999);
// 	ft_printf("s : %s\n", "aie aie aie");
// 	ft_printf("p : %p\n", (void *)123456);
// 	printf("printf p : %p\n", (void *)123456);
// 	ft_printf("x : %x\n", 254);
// 	ft_printf("X : %X\n", 254);
// 	ft_printf("pourcent : %%\n");
// 	ft_printf("i : %i\n", 78);
// 	ft_printf("u : %u\n", -78);
// 	printf("printf u : %u\n", -78);
// 	printf("printf d : %d\n", 54);
// 	printf("printf i : %i\n", 78);
// 	return (0);
// }
