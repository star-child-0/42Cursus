/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:55:43 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:55:56 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	ft_int_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str_num;

	len = ft_int_len(n);
	str_num = (char *)malloc(sizeof(char) * len + 1);
	if (!str_num)
		return (NULL);
	str_num[len] = '\0';
	if (n == 0)
		str_num[0] = '0';
	while (n)
	{
		str_num[--len] = (n % 10) + '0';
		n /= 10;
	}	
	return (str_num);
}

int	ft_print_nbr(int n, char flag)
{
	char	*num;
	int		num_len;

	num_len = 0;
	num = ft_itoa(n);
	if (flag == ' ' && n >= 0)
	{
		write(1, " ", 1);
		num_len++;
	}
	else if (flag == '+' && n >= 0)
	{
		write(1, "+", 1);
		num_len++;
	}
	num_len += ft_print_str(num);
	free(num);
	return (num_len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*num;
	int		num_len;

	num = ft_uitoa(n);
	num_len = ft_print_str(num);
	free(num);
	return (num_len);
}
