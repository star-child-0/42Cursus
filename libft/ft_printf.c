/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:01:22 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 15:04:21 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char *str, int i, va_list ptr)
{
	int	ret;

	ret = 0;
	if (str[i] == 'd' || str[i] == 'i')
		ret += ft_putnbr(va_arg(ptr, int));
	else if (str[i] == 'u')
		ret += ft_putunsign_nbr(va_arg(ptr, unsigned int));
	else if (str[i] == 'c')
		ret += ft_putchar(va_arg(ptr, int));
	else if (str[i] == 's')
		ret += ft_putstr(va_arg(ptr, char *));
	else if (str[i] == 'p')
		ret += ft_put_pointer(va_arg(ptr, uintptr_t));
	else if (str[i] == 'X' || str[i] == 'x')
		ret += ft_putnbr_hex(va_arg(ptr, unsigned int), str[i]);
	else if (str[i] == '%')
		ret += ft_putchar('%');
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	ptr;

	i = 0;
	ret = 0;
	va_start(ptr, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ret += ft_check(str, ++i, ptr);
		else
		{
			ft_putchar(str[i]);
			ret++;
		}
		i++;
	}
	va_end(ptr);
	return (ret);
}
