/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:36:52 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 17:36:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*str;

	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s1 || !s2 || !str)
		return (0);
	i = -1;
	k = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[++k] != '\0')
		str[++i] = s2[k];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i++] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}