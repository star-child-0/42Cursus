/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:19:00 by aurso             #+#    #+#             */
/*   Updated: 2022/10/17 19:19:50 by aurso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/types.h>
# include <stdio.h>

char	*ft_freejoint(char *fub, char *buf);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t dim, size_t num);
char	*get_next_line(int fd);
char	*ft_get_buff(char *fub, int fd);
char	*ft_get_fub(char *fub);
char	*ft_get_print(char *fub);

#endif
