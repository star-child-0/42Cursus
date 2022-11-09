/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:01:55 by aurso             #+#    #+#             */
/*   Updated: 2022/10/17 19:02:04 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freejoint(char *fub, char *buf)
{
	char	*str;

	str = ft_strjoin(fub, buf);
	free(fub);
	return (str);
}

char	*ft_get_buff(char *fub, int fd)
{
	char	*buf;
	int		check;

	check = 1;
	buf = ft_calloc(1, BUFFER_SIZE + 1);
	if (!fub)
		fub = ft_calloc(1, 1);
	while (check > 0)
	{
		check = read(fd, buf, BUFFER_SIZE);
		buf[check] = '\0';
		fub = ft_freejoint(fub, buf);
		if (ft_strchr(fub, '\n'))
			break ;
	}
	free(buf);
	return (fub);
}

char	*ft_get_fub(char *fub)
{
	int		i;
	int		z;
	char	*str;

	i = 0;
	z = 0;
	while (fub[i] && fub[i] != '\n')
		i++;
	if (fub[i] == '\0')
	{
		free(fub);
		return (NULL);
	}
	str = ft_calloc(1, (ft_strlen(fub) - i + 1));
	while (fub[++i])
		str[z++] = fub[i];
	free(fub);
	return (str);
}

char	*ft_get_print(char *fub)
{
	int		i;
	int		j;
	char	*sup;

	i = 0;
	j = 0;
	if (fub[i] == 0)
		return (NULL);
	while (fub[i] && fub[i] != '\n')
		i++;
	if (fub[i] == '\n')
		i++;
	sup = calloc((i + 1), sizeof(char));
	while (j < i)
	{
		sup[j] = fub[j];
		j++;
	}
	return (sup);
}

char	*get_next_line(int fd)
{
	static char	*fub;
	char		*print;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	fub = ft_get_buff(fub, fd);
	print = ft_get_print(fub);
	fub = ft_get_fub(fub);
	return (print);
}
