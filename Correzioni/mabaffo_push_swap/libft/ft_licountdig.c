/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_licountdig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:05:42 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/04 15:49:51 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_licountdig(long long int n)
{
	size_t	dig;

	if (n == 0)
		return (1);
	dig = (n < 0);
	while (n > 0)
	{
		n /= 10;
		dig++;
	}
	return (dig);
}
/*
 * '-' conta come digit
 */
