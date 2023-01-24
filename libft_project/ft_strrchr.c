/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:20:21 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:37:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)(&s[len]));
	while (--len >= 0)
	{
		if (s[len] == (unsigned char)c)
			return ((char *)(&s[len]));
	}
	return (NULL);
}
