/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:05:39 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/20 13:06:53 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_numlen(int n)
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

char	*ft_itoa(int n)
{
	int		len;
	char	*str_num;

	len = ft_get_numlen(n);
	str_num = (char *)malloc(sizeof(char) * len + 1);
	if (!str_num)
		return (NULL);
	str_num[len] = '\0';
	if (n < 0)
		str_num[0] = '-';
	else if (n == 0)
		str_num[0] = '0';
	while (n)
	{
		if (n > 0)
			str_num[--len] = (n % 10) + '0';
		else
			str_num[--len] = (n % 10 * -1) + '0';
		n /= 10;
	}	
	return (str_num);
}
