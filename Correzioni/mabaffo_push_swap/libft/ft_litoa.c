/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:16:11 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/04 15:49:08 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa(long int n)
{
	char			*str;
	char			*sstr;
	long long int	num;
	int				d;

	d = ft_licountdig(n);
	num = n;
	str = ft_calloc(d + 1, 1);
	if (!str)
		return (str);
	if (n == 0)
		str[0] = 48;
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		num = -num;
	while (num > 0)
	{
		str[--d] = "0123456789"[num % 10];
		num /= 10;
	}
	sstr = ft_strdup(&str[d]);
	free(str);
	return (sstr);
}
