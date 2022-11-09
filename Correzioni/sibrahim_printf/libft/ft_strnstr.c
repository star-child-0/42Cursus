/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:57:57 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/20 12:58:39 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	if (!haystack || !needle)
		return (NULL);
	if (!needle || !needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		k = 0;
		while (haystack[i + k] && needle[k] && i + k < len
			&& haystack[i + k] == needle[k])
			k++;
		if (!needle[k])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
