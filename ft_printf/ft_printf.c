/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:07:57 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/28 15:40:48 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percentchar(char a, va_list b)
{
	int	c;

	c = 0;
	if (a == 'c')
		return (ft_putchar(va_arg(b, int)));
	if (a == 's')
		return (ft_putstr(va_arg(b, char *)));
	if (a == 'p')
		return (ft_pointer_tohex(va_arg(b, unsigned long long)));
	if (a == 'd' || a == 'i')
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
	return (1);
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
			write(1, &format[j++], 1);
			i++;
		}
		if (format[j] == '%' && format[j++] != '\0')
			i += ft_percentchar(format[j], arg);
		if (format[j])
			j++;
	}
	va_end(arg);
	return (i);
}

// int	main(void)
// {
// 	// ft_printf("%c\n", 'a');
// 	// printf("%c\n", 'b');
// 	// ft_printf("%d\n", ft_printf("aaa\n"));
// 	// printf("%d\n", printf("bbb\n"));
// 	// ft_printf("d : %d\n", 9999);
// 	// ft_printf("s : %s\n", "aie aie aie");
// 	ft_printf("p : %p\n", (void *)"123456");
// 	printf("printf p : %p\n", (void *)"123456");
// 	// ft_printf("x : %x\n", 254);
// 	// ft_printf("X : %X\n", 254);
// 	// ft_printf("pourcent : %%\n");
// 	// ft_printf("i : %i\n", 78);
// 	// ft_printf("u : %u\n", -78);
// 	// printf("printf u : %u\n", -78);
// 	// printf("printf d : %d\n", 54);
// 	// printf("printf i : %i\n", 78);
// 	return (0);
// }
