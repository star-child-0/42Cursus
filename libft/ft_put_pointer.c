/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:07:47 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 15:09:30 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_pointer(uintptr_t ptr)
{
	long int	hex;

	hex = (long int)ptr;
	if (ptr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	ft_putstr("0x");
	if (hex <= -1)
		return (ft_putchar('f') + ft_putnbr_hex(hex, 'x') + 2);
	return (ft_putnbr_hex(ptr, 'x') + 2);
}
