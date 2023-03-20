/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:34:01 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/20 20:14:51 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	int		i;
	int		ret;
	va_list	ap;

	i = -1;
	ret = 0;
	va_start(ap, str);
	while (str[++i] != '\0')
	{
		else if (ret++)
			ft_putchar(str[i]);
	}
	va_end(ap);
	return (ret);
}
