/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:45:10 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/23 13:45:27 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_writeft(char a)
{
	//writes the character
	if (a == 'c')
		ft_newchar(a);
	//writes the string
	else if (a == 's')
		(void) a;
	//writes void expression in hexa
	else if (a == 'p')
		(void) a;
	//writes a decimal number
	else if (a == 'd')
		(void) a;
	//writes an integer
	else if (a == 'i')
		(void) a;
	//writes an unsigned decimal
	else if (a == 'u')
		(void) a;
	//writes hexa values with lowercases
	else if (a == 'x')
		(void) a;
	//writes hexa values with uppercases
	else if (a == 'X')
		(void) a;
	else if (a == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	void	*fval;
	va_list	valist;
	
	i = 0;
	if (!format)
		return (0);
	va_start(valist, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			fval = va_arg(valist, typeof(fval));
			//write fval depending the type of value
			ft_writeft(*fval);
			i++;
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(valist);
	return (i);
}

int	main()
{
	printf("coucou%c\n", 'a');
	ft_printf("coucou%c45\n", 'a');
	return (0);
}
