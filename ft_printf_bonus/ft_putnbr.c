/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:05:23 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/21 20:54:59 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	sign;

	sign = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == INT_MIN)
		{
			ft_putstr("2147483648");
			return (11);
		}
		else
			nb = -nb;
		sign++;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
	return (ft_nbrlen(nb) + sign);
}
