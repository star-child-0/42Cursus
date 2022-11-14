/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:28 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 15:07:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_assign(long unsigned int a, char c)
{
	if (a % 16 < 10)
		return (a % 16 + 48);
	else if (c == 'x')
		return (a % 16 + 87);
	else
		return (a % 16 + 55);
}

int	ft_putnbr_hex(unsigned long int nb, char x)
{
	int		i;
	int		r;
	char	*hex;

	i = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	nb *= 16;
	hex = malloc(1 * 21);
	while ((nb / 16) != 0)
	{
		nb /= 16;
		hex[i++] = ft_assign(nb, x);
	}
	hex[i] = ft_assign(nb, x);
	r = i;
	while (--i >= 0)
		ft_putchar(hex[i]);
	free(hex);
	return (r);
}
