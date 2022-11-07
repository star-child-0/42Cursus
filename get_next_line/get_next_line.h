/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:36:45 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 17:36:47 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif


# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int 	ft_strlen(const char *str);

char    *get_next_line(int fd);

#endif