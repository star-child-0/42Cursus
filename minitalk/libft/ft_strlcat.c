/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:18:17 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:18:19 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	k;
	size_t	j;

	len_dst = ft_strlen(dst);
	k = len_dst;
	j = 0;
	if (size <= len_dst)
		return (size + ft_strlen(src));
	while (j < (size - len_dst - 1) && src[j] != '\0')
	{
		dst[k] = src[j];
		k++;
		j++;
	}
	dst[k] = '\0';
	return (len_dst + ft_strlen(src));
}
