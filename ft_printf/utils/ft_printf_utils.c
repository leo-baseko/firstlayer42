/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:31:20 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/28 15:10:21 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
