/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:20:34 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/28 21:24:03 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	double	nb;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	nb = 0.0;
	power = 1.0;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	i += (s[i] == '-' || s[i] == '+');
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		i++;
	}
	i += (s[i] == '.');
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * nb / power);
}
