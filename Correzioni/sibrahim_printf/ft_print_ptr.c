/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:56:47 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:56:49 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int	ft_ptr_convert(int *num, int i, int len)
{
	char	digit;
	int		p_len;

	p_len = 0;
	while (i < len)
	{
		if (num[i] <= 9)
		{
			digit = num[i] + '0';
			write(1, &digit, 1);
		}
		else
		{
			digit = num[i] + 87;
			write(1, &digit, 1);
		}
		p_len++;
		i++;
	}
	return (p_len);
}

static int	ft_check_ptr_zero(unsigned long long p, int *num)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		free(num);
		return (1);
	}
	return (0);
}

int	ft_print_ptr(unsigned long long p)
{
	int	*num;
	int	len;
	int	i;
	int	p_len;

	p_len = 0;
	len = ft_ptr_len(p);
	i = len;
	num = malloc(sizeof(int) * len);
	if (!num)
		return (0);
	if (ft_check_ptr_zero(p, num))
		return (5);
	write(1, "0x", 2);
	p_len += 2;
	while (p)
	{
		num[i - 1] = p % 16;
		p /= 16;
		i--;
	}
	p_len += ft_ptr_convert(num, i, len);
	free(num);
	return (p_len);
}
