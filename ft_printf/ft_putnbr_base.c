/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:50 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/08 14:41:51 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_base(unsigned int nb, char *base, int len)
{
	int count;

	count = 0;
	if (nb < (unsigned int)len)
		return (write(1, &base[nb], 1));
	count += ft_putnbr_base(nb / len, base, len);
	return (count + ft_putnbr_base(nb % len, base, len));
}