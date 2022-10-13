/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarchio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:34:42 by smarchio          #+#    #+#             */
/*   Updated: 2022/10/07 18:21:19 by smarchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*newarr;
	size_t	x;

	x = nmemb * size;
	if (nmemb != 0 && x / nmemb != size)
		return (NULL);
	newarr = (void *)malloc(x);
	if (!newarr)
		return (NULL);
	ft_bzero(newarr, x);
	return (newarr);
}
