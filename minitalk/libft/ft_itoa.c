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

static short	ft_get_numsign(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

static size_t	ft_get_numlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static void	ft_strrev(char *s)
{
	char	*left;
	char	tmp;

	left = s;
	while (*s)
		s++;
	while (left < --s)
	{
		tmp = *left;
		*left++ = *s;
		*s = tmp;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	size_t		pos;
	short		sign;

	sign = ft_get_numsign(n);
	len = ft_get_numlen(n);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	pos = 0;
	while (n)
	{
		str[pos++] = sign * (n % 10) + '0';
		n /= 10;
	}
	if (!(n || pos))
		str[pos++] = '0';
	if (sign < 0)
		str[pos++] = '-';
	str[pos] = '\0';
	ft_strrev(str);
	return (str);
}
