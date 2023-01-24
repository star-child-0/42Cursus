/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:19:50 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:39:29 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		k = 0;
		while (big[i + k] == little[k] && (i + k) < len)
		{
			if (big[i + k] == '\0' && little[k] == '\0')
				return ((char *)&big[i]);
			k++;
		}
		if (little[k] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
