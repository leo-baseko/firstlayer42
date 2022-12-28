/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldrieske <ldrieske@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:41:33 by ldrieske          #+#    #+#             */
/*   Updated: 2022/12/28 15:40:25 by ldrieske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	ft_newchar(char a);
int		ft_putnbr_base(unsigned int nb, char *base, int len);
int		ft_putchar(int c);
int		ft_pointer_tohex(unsigned long long ptr);
int		ft_putstr(const char *str);

#endif
