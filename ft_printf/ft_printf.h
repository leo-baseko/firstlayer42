/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:41:33 by ldrieske          #+#    #+#             */
/*   Updated: 2023/01/07 16:00:36 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_base(unsigned int nbr, char *base, int len);
int		ft_putptr_base(unsigned long long ptr, char *base, int len);
int		ft_pointer_tohex(unsigned long long ptr);
int		ft_putchar(int c);
int		ft_putstr(const char *str);

#endif
