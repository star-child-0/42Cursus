/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:47:05 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/15 20:47:08 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_struint(char *ptr, unsigned long u)
{
	unsigned int	i;

	i = 0;
	if (u == 0)
	{	
		ptr[i] = '0';
		i++;
	}
	while (u != 0)
	{
		*(ptr + i) = (u % 10) + 48;
		u = u / 10;
		i++;
	}
	ptr[i] = '\0';
	return (ft_strrev(ptr, i));
}

void	ft_print_lowhex(unsigned long x, t_flags *flag)
{	
	char	*hex;

	if (x == 0 && flag->prec == 0 && flag->punto)
	{
		flag->len = 0;
		return ;
	}
	hex = ft_dectohex_low(x);
	flag->len = ft_strlen(hex);
	if (x == 0)
		write(1, "0", 1);
	else
	{
		if (flag->canc)
			write(1, "0x", 2);
		ft_putnstr_fd(hex, flag->len, 1);
	}
	free (hex);
}

void	ft_print_uphex(unsigned long X, t_flags *flag)
{	
	char	*hex;

	if (X == 0 && flag->prec == 0 && flag->punto & !flag->zero)
	{
		flag->len = 0;
		return ;
	}
	hex = ft_dectohex_upper(X);
	flag->len = ft_strlen(hex);
	if (X == 0)
		write(1, "0", 1);
	else
	{
		if (flag->canc)
			write(1, "0X", 2);
		ft_putnstr_fd(hex, flag->len, 1);
	}
	free (hex);
}

void	ft_put_lowx(unsigned int x, t_flags *flag)
{
	if (x == 0 && flag->punto && !flag->prec && !flag->meno)
		flag->len = 0;
	else
		flag->len = ft_hexlen(x);
	if (flag->canc && x != 0)
		flag->ret += 2;
	if (!flag->zero && !flag->meno && flag->wdt > flag->prec)
		ft_print_space(flag);
	if (flag->zero)
		ft_print_zero(flag);
	ft_printprec(flag);
	ft_print_lowhex(x, flag);
	if (!(x == 0 && flag->prec == 0 && flag->punto))
		flag->ret += flag->len;
	if (flag->meno)
		ft_print_space(flag);
}

void	ft_put_upx(unsigned int x, t_flags *flag)
{
	if (x == 0 && flag->punto && !flag->prec && !flag->meno)
		flag->len = 0;
	else
		flag->len = ft_hexlen(x);
	if (flag->canc && x != 0)
		flag->ret += 2;
	if (!flag->zero && !flag->meno && flag->wdt > flag->prec)
		ft_print_space(flag);
	if (flag->zero)
		ft_print_zero(flag);
	ft_printprec(flag);
	ft_print_uphex(x, flag);
	if (!(x == 0 && flag->prec == 0 && flag->punto))
		flag->ret += flag->len;
	if (flag->meno)
		ft_print_space(flag);
}
