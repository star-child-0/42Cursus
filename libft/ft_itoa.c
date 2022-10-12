/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:11:23 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/12 19:04:49 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_number_size(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 2);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	c;

	i = 0;
	l = ft_strlen(str);
	while (i < l / 2)
	{
		c = str[i];
		str[i] = str[l - i - 1];
		str[l - i - 1] = c;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		n_size;
	char	*str;

	i = 0;
	n_size = get_number_size(n);
	str = (char *)malloc(n_size);
	while (i < n_size)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	if (n < 0)
		str[i] = '-';
	else
		str[i] = '+';
	return (ft_strrev(str));
}
