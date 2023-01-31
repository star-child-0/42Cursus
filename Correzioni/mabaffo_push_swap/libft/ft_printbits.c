/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:48:11 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/03 11:55:51 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printbits(unsigned char c)
{
	int				i;
	unsigned char	revbits[8];

	i = 0;
	while (i < 8)
	{
		revbits[i] = c % 2 + 48;
		if (c)
			c /= 2;
		i++;
	}
	while (--i >= 0)
		write(1, &revbits[i], 1);
	write(1, " ", 1);
}
