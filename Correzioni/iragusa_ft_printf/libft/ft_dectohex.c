/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:10:24 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/12 15:13:02 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dectohex_len(unsigned long num)
{
	int					j;
	unsigned long		all;

	all = num;
	if (all == 0)
		return (1);
	j = 0;
	while (all != 0)
	{
		all /= 16;
		j++;
	}
	return (j);
}

char	*ft_dectohex_upper(unsigned long num)
{
	int		resto;
	int		j;
	char	*hex;

	j = ft_dectohex_len(num);
	hex = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	if (num == 0)
	{	
		hex[j] = '0';
		j++;
	}
	while (num != 0)
	{
		resto = num % 16;
		if (resto < 10)
			hex[j++] = 48 + resto;
		else
			hex[j++] = 55 + resto;
		num = num / 16;
	}
	hex[j] = '\0';
	return (ft_strrev(hex, j));
}

char	*ft_dectohex_low(unsigned long num)
{
	int		resto;
	int		j;
	char	*hex;

	j = ft_dectohex_len(num);
	hex = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	if (num == 0)
	{	
		hex[j] = '0';
		j++;
	}
	while (num != 0)
	{
		resto = num % 16;
		if (resto < 10)
			hex[j++] = 48 + resto;
		else
			hex[j++] = 87 + resto;
		num = num / 16;
	}
	hex[j] = '\0';
	return (ft_strrev(hex, j));
}
