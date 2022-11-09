/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:56:06 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:56:15 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static char	ft_check_flag(const char f, const char *s)
{
	if (f == '#')
	{
		if (*(s + 1) == 'x' || *(s + 1) == 'X')
			return (f);
		else
			return ('e');
	}
	else if (f == ' ')
	{
		if (*(s + 1) == 'd' || *(s + 1) == 'i')
			return (f);
		else
			return ('e');
	}
	else if (f == '+')
	{
		if (*(s + 1) == 'd' || *(s + 1) == 'i')
			return (f);
		else
			return ('e');
	}
	return ('e');
}

static int	ft_check_format(va_list args, const char *s)
{
	int		len;
	char	flag;

	flag = 'n';
	len = 0;
	if (*s == '+' || *s == '#' || *s == ' ')
	{
		flag = ft_check_flag(*s, s);
		s++;
	}
	if (*s == 'c')
		len = ft_print_char(va_arg(args, int));
	else if (*s == 'd' || *s == 'i' || flag == ' ' || flag == '+')
		len = ft_print_nbr(va_arg(args, int), flag);
	else if (*s == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (*s == 'p')
		len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (*s == 'u')
		len = ft_print_unsigned(va_arg(args, unsigned int));
	else if (*s == 'x' || *s == 'X' || flag == '#')
		len = ft_print_hex(va_arg(args, unsigned int), *s, flag);
	else if (*s == '%')
		len = ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total_len;

	total_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			total_len += ft_print_char(*str);
		else
		{
			total_len += ft_check_format(args, str + 1);
			if (*(str + 1) == '#' || *(str + 1) == '+' || *(str + 1) == ' ')
				str += 1;
			str++;
		}
		str++;
	}
	va_end(args);
	return (total_len);
}
