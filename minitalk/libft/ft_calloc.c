/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:10:02 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/15 20:14:00 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*arr;
	size_t		i;

	i = nmemb * size;
	if (nmemb && i / nmemb != size)
		return (NULL);
	arr = (void *)malloc(i);
	if (!arr)
		return (NULL);
	ft_bzero(arr, i);
	return (arr);
}
