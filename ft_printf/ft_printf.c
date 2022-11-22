/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:45:10 by ldrieske          #+#    #+#             */
/*   Updated: 2022/11/22 15:02:44 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

strict void	ft_writeft(char a)
{
	if (a == 'c')
		
}

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*fval;
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
	ft_printf("coucou45\n");
	return (0);	
}
