/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:51:34 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/10 19:50:42 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_space_s(t_flags *flag)
{	
	int	diff;

	if (flag->len < flag->wdt)
	{
		diff = flag->wdt - flag->len;
		while (diff-- > 0)
		{
			ft_putchar(' ');
			flag->ret ++;
		}
	}
}

void	ft_p_null(t_flags *flag)
{
	if (!flag->meno)
		ft_print_space(flag);
	ft_putstr_fd("(nil)\0", 1);
	flag->ret += 5;
	if (flag->meno)
		ft_print_space(flag);
}

void	ft_put_c(int c, t_flags *flag)
{
	char	a;

	a = c;
	flag->len = 1;
	if (!flag->meno)
		ft_print_space(flag);
	ft_putchar_fd(a, 1);
	flag->ret++;
	if (flag->meno)
		ft_print_space(flag);
}

void	ft_put_s(char *s, t_flags *flag)
{
	if (!s)
	{
		if (!flag->prec || flag->prec > 5)
			s = "(null)\0";
		else
			s = "";
	}
	flag->len = ft_strlen(s);
	if (flag->len > flag->prec && flag->punto)
		flag->len = flag->prec;
	if (!flag->meno)
		ft_print_space_s(flag);
	ft_putnstr_fd(s, flag->len, 1);
	flag->ret += flag->len;
	if (flag->meno == 1)
		ft_print_space(flag);
}

//if p 
void	ft_put_p(unsigned long p, t_flags *flag)
{	
	if (!p)
	{
		flag->len = 5;
		ft_p_null(flag);
		return ;
	}
	flag->len = ft_hexlen(p) + 2;
	if (!flag->meno)
		ft_print_space(flag);
	if (flag->sign || (flag->sp && flag->meno))
		ft_print_sign(p, flag);
	ft_putstr_fd("0x", 1);
	ft_print_lowhex(p, flag);
	if (flag->meno)
	{	
		flag->len += 2;
		flag->ret -= 2;
		ft_print_space(flag);
	}
	flag->ret += flag->len + 2;
}
