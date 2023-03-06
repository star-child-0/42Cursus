/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:04:57 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/23 19:15:39 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_intl **list)
{
	int		temp;

	if ((*list) && (*list)->next)
	{
		temp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = temp;
	}
	ft_printf("sa\n");
}

void	sb(t_intl **list)
{
	int		temp;

	if ((*list) && (*list)->next)
	{
		temp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = temp;
	}
	ft_printf("sb\n");
}

void	ss(t_intl **list_a, t_intl **list_b)
{
	int		temp;

	if ((*list_a) && (*list_a)->next)
	{
		temp = (*list_a)->content;
		(*list_a)->content = (*list_a)->next->content;
		(*list_a)->next->content = temp;
	}
	if ((*list_b) && (*list_b)->next)
	{
		temp = (*list_b)->content;
		(*list_b)->content = (*list_b)->next->content;
		(*list_b)->next->content = temp;
	}
	ft_printf("ss\n");
}
