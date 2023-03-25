/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:10:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 19:32:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	space_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	n;
	int	j;

	if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		n = va_arg(args, int);
		if (n >= 0)
			flags->ret += ft_putchar(' ');
		flags->ret += ft_putnbr(n);
	}
	else
	{
		while (str[i + 1] >= '0' && str[i + 1] <= '9')
		{
			j = ft_atoi(&str[i + 1]);
			i += j;
			while (j--)
				flags->ret += ft_putchar(' ');
		}
		flags->ret += ft_putstr(va_arg(args, char *));
	}
	return (++i);
}
