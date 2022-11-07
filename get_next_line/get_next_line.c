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

char    *file_read(int fd, char *stash)
{
    int     bytes;
    char    *buffer;

    buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (buffer)
    {
        bytes = 1;
        while (bytes != 0 && !ft_strchr(stash, '\n'))
        {
            bytes = read(fd, buffer, BUFFER_SIZE);
            if (bytes == -1)
            {
                free(stash);
                return (NULL);
            }
            buffer[bytes] = '\0';
            stash = ft_strjoin(stash, buffer);
        }
        free(buffer);
        return (stash);
    }
    return (NULL);
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
    i = -1;
    while (stash[++i] != '\n')
        line[i] = stash[i];
    if (stash[++i] == '\n')
        line[i] = '\n';
    line[++i] = '\0';
    return (line);
}

char    *new_line(char *stash)
{
    int     i;
    int     j;
    char    *nl;

    i = 0;
    j = -1;
    while (stash[i] != '\0' && stash[i] != '\n')
        i++;
    if (stash[i] != '\0')
    {
        free(stash);
        return (NULL);
    }
    nl = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
    while (stash[++j + i] != '\0')
        nl[j] = stash[i + j];
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
    free(stash);
    return (line);
}

int main()
{
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdio.h>

    int     fd = open("txt1.txt", 'r');
    printf("%s", get_next_line(fd));
    close(fd);
}