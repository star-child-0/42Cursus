/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_sa(t_intl **list)
{
	int		temp;

	if ((*list) && (*list)->next)
	{
		temp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = temp;
	}
}

void	do_sb(t_intl **list)
{
	int		temp;

	if ((*list) && (*list)->next)
	{
		temp = (*list)->content;
		(*list)->content = (*list)->next->content;
		(*list)->next->content = temp;
	}
}

void	do_pa(t_intl **list_b, t_intl **list_a)
{
	t_intl	*tmp;

	tmp = (*list_b);
	if ((*list_b)->next)
	{
		(*list_b) = (*list_b)->next;
		tmp->next = (*list_a);
		(*list_a) = tmp;
	}
	else
	{
		tmp->next = (*list_a);
		(*list_a) = tmp;
	}
}

void	do_pb(t_intl **list_a, t_intl **list_b)
{
	t_intl	*tmp;

	if (list_b != NULL)
	{
		tmp = (*list_a);
		(*list_a) = (*list_a)->next;
		tmp->next = (*list_b);
		(*list_b) = tmp;
	}
	else
	{
		(*list_b) = (*list_a);
		(*list_a) = (*list_a)->next;
		(*list_b)->next = NULL;
	}
}

void	do_ra(t_intl **list)
{
	int		temp;
	t_intl	*anchor;

	anchor = (*list);
	while (anchor)
	{
		if (anchor && anchor->next)
		{
			temp = anchor->content;
			anchor->content = anchor->next->content;
			anchor->next->content = temp;
		}
		anchor = anchor->next;
	}
}
