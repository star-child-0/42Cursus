/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:12:57 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:33:58 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (str2[i] > str1[i])
			return (1);
		else if (str1[i] > str2[i])
			return (-1);
		i++;
	}
	return (0);
}
