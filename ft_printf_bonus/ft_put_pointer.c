/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:07:47 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 16:18:48 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_ptr(uintptr_t ptr, char *base)
{
	int		i;
	int		conv[100];
	int		ret;

	i = 0;
	ret = 0;
	if (!ptr)
		return (0);
	while (ptr >= 16)
	{
		conv[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	conv[i] = base[ptr];
	while (i >= 0)
	{
		write(1, &conv[i], 1);
		i--;
		ret++;
	}
	return (ret);
}

int	ft_put_pointer(uintptr_t ptr)
{
	if (!ptr)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_ptr(ptr, "0123456789abcdef") + 2);
}
