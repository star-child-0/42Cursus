/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:56:58 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:57:00 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	s_len;

	s_len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	while (*s)
	{
		write(1, s, 1);
		s_len++;
		s++;
	}
	return (s_len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
