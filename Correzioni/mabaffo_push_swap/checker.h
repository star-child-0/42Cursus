/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:43:26 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/14 15:16:08 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <limits.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);

#endif
