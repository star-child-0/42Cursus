/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:47:08 by iragusa           #+#    #+#             */
/*   Updated: 2022/10/29 19:27:05 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	*ft_inizializza_flag(t_flags *flag)
/*imposta tutte le flags su falso*/
{
	flag->meno = 0;
	flag->zero = 0;
	flag->punto = 0;
	flag->sp = 0;
	flag->sign = 0;
	flag->canc = 0;
	flag->wdt = 0;
	flag->prec = 0;
	flag->len = 0;
	return (flag);
}

void	ft_printsrc(const char *src, t_flags *flag)
/*stampa quello che c'e' prima del %!*/
{
	write(1, src, 1);
	flag->ret++;
}

int	ft_printf(const char *src, ...)
{
	int		ret;
	t_flags	*flag;

	ret = 0;
	flag = (t_flags *)malloc(sizeof(t_flags));
	if (!flag || !src)
		return (-1);
	va_start(flag->next, src);
	flag->ret = 0;
	while (*src)
	{
		if (*src != '%')
			ft_printsrc(src, flag);
		else
		{	
			flag = ft_inizializza_flag(flag);
			src = ft_checkchar(flag, src + 1);
		}
		src++;
	}
	va_end(flag->next);
	ret = flag->ret;
	free(flag);
	return (ret);
}
