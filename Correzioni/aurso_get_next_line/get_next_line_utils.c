/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:02:17 by aurso             #+#    #+#             */
/*   Updated: 2022/10/17 19:05:48 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)str;
	while (p[i] != 0)
	{
		if (p[i] == c)
			return (&p[i]);
		i++;
	}
	if (p[i] == c)
		return (&p[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	newstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!newstr || !s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}

void	*ft_calloc(size_t dim, size_t num)
{
	char	*ret;
	size_t	i;

	ret = malloc(dim * num);
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	i = -1;
	while (++i < (dim * num))
		ret[i] = '\0';
	return (ret);
}
