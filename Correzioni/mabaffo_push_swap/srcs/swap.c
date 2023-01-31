/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:41:39 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/07 15:57:51 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pswap(void **p1, void **p2)
{
	void	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void	ft_sab(t_list *top)
{
	if (top && top->next)
		ft_pswap(&(top->content), &(top->next->content));
}

void	ft_sa(t_list *ta)
{
	ft_printf("sa\n");
	ft_sab(ta);
}

void	ft_sb(t_list *tb)
{
	ft_printf("sb\n");
	ft_sab(tb);
}

void	ft_ss(t_list *top_a, t_list *top_b)
{
	ft_printf("ss\n");
	ft_sab(top_a);
	ft_sab(top_b);
}
