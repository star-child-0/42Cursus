/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:28 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 18:21:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		i;
	int		conv[100];
	int		ret;

	i = 0;
	ret = 0;
	if (!nbr)
		return (0);
	while (nbr >= 16)
	{
		conv[i] = base[nbr % 16];
		nbr = nbr / 16;
		i++;
	}
	conv[i] = base[nbr];
	while (i >= 0)
	{
		write(1, &conv[i], 1);
		i--;
		ret++;
	}
	return (ret);
}

int	ft_putnbr_hex(unsigned long int nb, char x)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (x == 'x')
		len += ft_putnbr_base(nb, "0123456789abcdef");
	else if (x == 'X')
		len += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (len);
}
