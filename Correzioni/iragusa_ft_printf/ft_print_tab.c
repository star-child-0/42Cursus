/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:39:49 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/06 13:40:04 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_sign(int d, t_flags *flag)
{
	if (d >= 0)
	{
		if (flag->sp || flag->sign)
		{
			if (flag->sign)
				ft_putchar_fd('+', 1);
			else
				ft_putchar_fd(' ', 1);
			flag->ret += 1;
			flag->wdt -= 1;
		}
	}		
}

void	ft_printprec(t_flags *flag)
{
	int	diff;

	if (flag->len < flag->prec)
	{
		diff = flag->prec - flag->len;
		while (diff-- > 0)
		{
			ft_putchar_fd('0', 1);
			flag->ret++;
		}
	}
	if (flag->meno && (flag->prec - flag->len) > 0)
		flag->wdt -= (flag->prec - flag->len);
}

void	ft_print_zero(t_flags *flag)
{
	int	tab;

	tab = flag->wdt - flag->len;
	if (!flag->meno && flag->zero)
	{	
		while (tab-- > 0)
		{
			ft_putchar_fd('0', 1);
			flag->ret++;
			flag->wdt--;
		}
	}
}

void	ft_print_space2(t_flags *flag)
{
	int	diff;

	if (flag->prec > flag->len && !flag->meno)
		diff = flag->wdt - flag->prec;
	else
		diff = flag->wdt - flag->len;
	while (diff-- > 0)
	{
		ft_putchar_fd(' ', 1);
		flag->ret++;
	}
}	

void	ft_print_space(t_flags *flag)
{
	int	tab;

	tab = flag->wdt - flag->len;
	if (flag->len < flag->wdt && !flag->zero)
		ft_print_space2(flag);
	else if (!flag->meno && flag->zero)
	{
		while (tab-- > 0)
		{
			ft_putchar_fd('0', 1);
			flag->ret++;
		}
	}
}
