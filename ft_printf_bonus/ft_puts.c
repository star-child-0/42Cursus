/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 20:35:17 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/22 19:42:19 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_d_i(const char *str, int i, va_list args, t_flags *flags)
{
	int	n;

	n = va_arg(args, int);
	if (str[i] == ' ' && n >= 0)
		flags->ret += ft_putchar(' ');
	else if (str[i] == '+' && n >= 0)
		flags->ret += ft_putchar('+');
	else if (str[i] == '.' && n < 0 && flags->ret++ > -1)
		n *= -ft_putchar('-');
	else if (str[i] == '-' && flags->ret++ > -1)
		i++;
	flags->ret += ft_putnbr(n);
	return (++i);
}

int	put_c(const char *str, int i, va_list args, t_flags *flags)
{
	if (str[i] == '-')
		flags->ret += ft_putchar(va_arg(args, int));
	return (++i);
}

