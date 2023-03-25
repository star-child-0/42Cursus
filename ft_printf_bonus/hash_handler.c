/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:48:15 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 18:18:02 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hash_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	n;

	n = va_arg(args, int);
	if (str[i + 1] == 'x' && n)
		flags->ret += ft_putstr("0x") + ft_putnbr_hex(n, 'x');
	else if (str[i + 1] == 'X' && n)
		flags->ret += ft_putstr("0X") + ft_putnbr_hex(n, 'X');
	else if (str[i + 1] == 'x' && !n)
		flags->ret += ft_putnbr_hex(n, 'X');
	else if (str[i + 1] == 'X' && !n)
		flags->ret += ft_putnbr_hex(n, 'X');
	return (++i);
}
