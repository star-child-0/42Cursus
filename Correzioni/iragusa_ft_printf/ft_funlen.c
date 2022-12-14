/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:26:03 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/06 20:29:07 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_ptr_len(unsigned long int ptr, t_flags *flag)
{
	size_t	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0)
	{	
		len++;
		ptr = ptr / 16;
	}
	if (flag->sign)
		len++;
	return (len);
}

size_t	ft_numlen(int d)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = ft_itoa(d);
	i = ft_strlen(ptr);
	free (ptr);
	return (i);
}

size_t	ft_uintlen(unsigned int u)
{
	size_t	i;

	i = 0;
	if (u == 0)
		i = 1;
	while (u != 0)
	{
		u = u / 10;
		i++;
	}
	return (i);
}

size_t	ft_hexlen(unsigned long x)
{
	char	*hex;
	int		len;

	if (x == 0)
		return (1);
	hex = ft_dectohex_low(x);
	len = ft_strlen(hex);
	free (hex);
	return (len);
}
