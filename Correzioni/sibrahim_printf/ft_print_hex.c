/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:56:27 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:58:05 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned long long n)
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

static int	ft_hex_format(int *num, int i, int len, char format)
{
	char	digit;
	int		hex_len;

	hex_len = 0;
	while (i < len)
	{
		if (num[i] <= 9)
		{
			digit = num[i] + '0';
			write(1, &digit, 1);
		}
		else
		{
			if (format == 'x')
				digit = num[i] + 87;
			else if (format == 'X')
				digit = num[i] + 55;
			write(1, &digit, 1);
		}
		hex_len++;
		i++;
	}
	return (hex_len);
}

static int	ft_check_flag(char flag, char format, unsigned int n)
{
	if (flag == '#' && format == 'x' && n > 0)
		write(1, "0x", 2);
	else if (flag == '#' && format == 'X' && n > 0)
		write(1, "0X", 2);
	if (flag == '#')
		return (2);
	else
		return (0);
}

static int	ft_check_if_zero(unsigned int n, int *num)
{
	if (n == 0)
	{
		write(1, "0", 1);
		free(num);
		return (1);
	}
	return (0);
}

int	ft_print_hex(unsigned int n, char format, char flag)
{
	int	*num;
	int	len;
	int	i;
	int	h_len;

	h_len = 0;
	len = ft_hex_len((unsigned long long)n);
	i = len;
	num = malloc(sizeof(int) * len);
	if (!num)
		return (0);
	h_len += ft_check_flag(flag, format, n);
	if (ft_check_if_zero(n, num))
		return (1);
	while (n)
	{
		num[i - 1] = n % 16;
		n /= 16;
		i--;
	}
	h_len += ft_hex_format(num, i, len, format);
	free(num);
	return (h_len);
}
