/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:09:41 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/20 13:09:43 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	void	*p;

	if (b == NULL)
		return (NULL);
	p = b;
	while (len)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
		len--;
	}
	return (p);
}
