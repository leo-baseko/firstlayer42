/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:50 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/13 13:47:56 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base(unsigned int nb, char *base, int len)
{
	int	count;

	count = 0;
	if (nb < (unsigned int)len)
		return (write(1, &base[nb], 1));
	count += ft_putnbr_base(nb / len, base, len);
	return (count + ft_putnbr_base(nb % len, base, len));
}

int	ft_pointer_tohex(void *p, char *base, int len)
{
	int				count;
	unsigned int	nb;

	nb = (int)p;
	count = 0;
	write(1, "0x", 2);
	if (nb < (unsigned int)len)
		return (write(1, &base[nb], 1));
	count += ft_putnbr_base(nb / len, base, len);
	return (count + ft_putnbr_base(nb % len, base, len));
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
