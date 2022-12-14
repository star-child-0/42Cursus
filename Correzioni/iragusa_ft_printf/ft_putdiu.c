/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdiu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:51:34 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/10 19:50:42 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_numzero(t_flags *flag)
{
	if (flag->punto && !flag->prec)
	{
		flag->wdt ++;
		ft_print_zero(flag);
		return ;
	}
	else
	{
		ft_printprec(flag);
		ft_print_sign(0, flag);
		ft_print_zero(flag);
		write(1, "0", 1);
		flag->ret += 1;
	}
}

void	ft_print_num(char *ptr, int n, t_flags *flag)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		ft_printprec(flag);
		ft_print_zero(flag);
		flag->ret++;
	}
	i = ft_strnum(ptr, n) - 1;
	if ((flag->sign || flag->sp) && !flag->zero)
		ft_print_sign(n, flag);
	if (n >= 0)
		ft_printprec(flag);
	while (i > 0)
	{
		write(1, (ptr + i), 1);
		flag->ret++;
		i--;
	}
}

void	ft_putint(int n, t_flags *flag)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (flag->len + 1));
	if (n == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_print_sign(n, flag);
		ft_printprec(flag);
		ft_print_zero(flag);
		ft_putstr_fd("2147483648", 1);
		flag->ret += 11;
	}
	else if (n == 0)
		ft_print_numzero(flag);
	else
		ft_print_num(ptr, n, flag);
	free (ptr);
}

void	ft_put_di(int d, t_flags *flag)
{
	if (d == 0 && flag->punto && !flag->prec && !flag->meno)
		flag->len = 0;
	else
		flag->len = ft_numlen(d);
	if (d < 0)
		flag->prec++;
	ft_intflag(d, flag);
	if (flag->zero && d >= 0)
	{
		ft_print_sign(d, flag);
		ft_print_zero(flag);
	}
	ft_putint(d, flag);
	if (!flag->zero && flag->meno)
	{	
		if (((flag->sign || flag->sp) && d >= 0))
			flag->wdt--;
		ft_print_space(flag);
	}
}

void	ft_put_u(unsigned long u, t_flags *flag)
{
	char	*uint;

	if (u == 0 && flag->punto && !flag->prec && !flag->meno)
		flag->len = 0;
	else
		flag->len = ft_uintlen(u);
	uint = (char *)malloc(sizeof(char) * (flag->len + 1));
	uint = ft_struint(uint, u);
	ft_uint_flag(flag);
	if (u == 0)
		ft_print_numzero(flag);
	else
	{	
		ft_printprec(flag);
		ft_putnstr_fd(uint, flag->len, 1);
		flag->ret += flag->len;
	}
	if (flag->meno)
		ft_print_space(flag);
	free (uint);
}
