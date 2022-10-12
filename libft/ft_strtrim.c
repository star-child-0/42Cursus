/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:20:54 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:51:59 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		l;
	char	*str;

	i = 0;
	j = 0;
	l = ft_strlen(s1);
	str = malloc(l);
	while (i < l)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				ft_memmove(str + i, str + i + 1, (size_t)l);
			j++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
