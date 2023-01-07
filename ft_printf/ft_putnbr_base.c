/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:50 by ldrieske          #+#    #+#             */
/*   Updated: 2023/01/07 16:00:22 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, int len)
{
	int	count;

	if (nbr < (unsigned int)len)
		return (write(1, &base[nbr], 1));
	count = ft_putnbr_base(nbr / len, base, len);
	return (count + ft_putnbr_base(nbr % len, base, len));
}

int	ft_putptr_base(unsigned long long ptr, char *base, int len)
{
	int	count;

	if (ptr < (unsigned int)len)
		return (write(1, &base[ptr], 1));
	count = ft_putptr_base(ptr / len, base, len);
	return (count + ft_putptr_base(ptr % len, base, len));
}

int	ft_pointer_tohex(unsigned long long ptr)
{
	int	i;

	write(1, "0x", 2);
	i = ft_putptr_base(ptr, "0123456789abcdef", 16);
	return (i + 2);
}
