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
#define BUFFER_SIZE 42
#include <fcntl.h>

char    *join_and_free(char *buffer, char *buf)
{
    char    *temp;

    temp = ft_strjoin(buffer, buf);
    free(buf);
    return (temp);
}

char    *file_read(int fd, char *buf)
{
    int     nbytes;
    char    *buffer;

    if (!buf)
        buf = ft_calloc(1, 1);
    nbytes = 1;
    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    while (nbytes != 0)
    {
        nbytes = read(fd, buf, BUFFER_SIZE);
        if (nbytes == -1)
        {
            free(buffer);
            return (NULL);
        }
        buffer[nbytes] = 0;
        buffer = join_and_free(buffer, buf);
        if (ft_strchr(buffer, '\n'))
            break ;
    }
    free(buffer);
    return (buf);
}

char    *get_next_line(int fd)
{
    static char     *buffer;
    char            *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = file_read(fd, buffer);
    if (!buffer)
        return (NULL);
    
    return (line);
}