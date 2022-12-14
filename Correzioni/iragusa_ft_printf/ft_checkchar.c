/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:05:03 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/01 15:39:54 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

const char	*ft_isflag(t_flags *flag, const char *src)
{
	while (ft_findchar(*src, " -0+#"))
	{
		if (*src == ' ')
			flag->sp = 1;
		if (*src == '-')
			flag->meno = 1;
		if (*src == '0')
			flag->zero = 1;
		if (*src == '+')
			flag->sign = 1;
		if (*src == '#')
			flag->canc = 1;
		src++;
	}
	return (src);
}

const char	*ft_convchar(t_flags *flag, const char *src)
{	
	if (*src == 'c')
		ft_put_c(va_arg(flag->next, int), flag);
	if (*src == 's')
		ft_put_s(va_arg(flag->next, char *), flag);
	if (*src == 'p')
		ft_put_p(va_arg(flag->next, unsigned long), flag);
	if (*src == 'd' || *src == 'i')
		ft_put_di(va_arg(flag->next, int), flag);
	if (*src == 'u')
		ft_put_u(va_arg(flag->next, unsigned int), flag);
	if (*src == 'x')
		ft_put_lowx(va_arg(flag->next, unsigned int), flag);
	if (*src == 'X')
		ft_put_upx(va_arg(flag->next, unsigned int), flag);
	else if (*src == '%')
	{
		ft_putchar('%');
		flag->ret += 1;
	}
	return (src);
}

const char	*ft_checkchar(t_flags *flag, const char *src)
{
	while (!ft_findchar(*src, "cspdiuxX%"))
	{
		src = ft_isflag(flag, src);
		src = ft_wdt(flag, src);
		src = ft_prec(flag, src);
	}
	if (ft_findchar(*src, "cspdiuxX%"))
		ft_convchar(flag, src);
	return (src);
}
