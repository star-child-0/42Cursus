/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:36:40 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 17:36:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

//--------------------------------------------------------------------
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
    int     i;
    int     j;
    char    *str;

    i = -1;
    j = -1;
    if (!s1)
    {
        s1 = (char *)malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
    str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    while (s1[++i] != '\0')
        str[i] = s1[i];
    while (s2[++j + i] != '\0')
        str[j + i] = s2[j];
    str[++j + i] = '\0';
    free(s1);
    return(str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[i]);
    while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
        i++;
    }
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
//--------------------------------------------------------------------

char    *file_read(int fd, char *stash)
{
    int     bytes;
    char    *buffer;

    buffer = malloc((BUFFER_SIZE + 1 )* sizeof(char));
    if (!buffer)
        return (NULL);
    bytes = 1;
    while (bytes != 0 && !ft_strchr(stash, '\n'))
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}

char    *trim_stash(char *stash)
{
    int     i;
    char    *line;

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    line = malloc((i + 2) * sizeof(char));
    if (!line)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
    {
        line[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *new_line(char *stash)
{
    int     i;
    int     j;
    char    *nl;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    nl = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
    if (!nl)
        return (NULL);
    i++;
    while (stash[j])
        nl[j++] = stash[i++];
    nl[j] = '\0';
    free(stash);
    return (nl);
}

char    *get_next_line(int fd)
{
    static char     *stash;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = file_read(fd, stash);
    if (!stash)
        return (NULL);
    line = trim_stash(stash);
    stash = new_line(stash);
    return (line);
}

int main()
{
    #include <stdio.h>
    #include <fcntl.h>

    int     fd = open("txt1.txt", 'r');
    printf("%s", get_next_line(fd));
    printf("\n");
    close(fd);
}