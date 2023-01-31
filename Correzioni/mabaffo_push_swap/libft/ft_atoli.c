/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:57:20 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/04 15:50:40 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoli(const char *nptr)
{
	size_t			i;
	long long int	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 0;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign++;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num = num * 10 + nptr[i] - 48;
		i++;
	}
	if (sign)
		num = -num;
	return (num);
}
