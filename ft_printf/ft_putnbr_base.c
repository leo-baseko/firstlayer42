/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:50 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/28 15:42:08 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base, int len)
{
	int	count;

	count = 0;
	if (nb < (unsigned int)len)
		return (write(1, &base[nb], 1));
	count += ft_putnbr_base(nb / len, base, len);
	return (count + ft_putnbr_base(nb % len, base, len));
}

int	ft_pointer_tohex(unsigned long long ptr)
{
	int	i;

	write(1, "0x", 2);
	i = ft_putnbr_base((unsigned int)ptr, "0123456789abcdef", 16);
	return (i + 2);
}
