/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:07:31 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/20 13:07:33 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i))
		i++;
	while (i >= 0)
	{
		if (*(char *)(s + i) == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
