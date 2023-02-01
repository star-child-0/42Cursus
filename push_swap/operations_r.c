/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:04:39 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/01 19:20:28 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_intl **list)
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
	ft_printf("ra\n");
}

void	rb(t_intl **list)
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
	ft_printf("rb\n");
}

void	rr(t_intl **list_a, t_intl **list_b)
{
	int		temp;
	t_intl	*anchor;

	anchor = (*list_a);
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
	rr_2(list_b);
	ft_printf("rr\n");
}

void	rr_2(t_intl **list_b)
{
	int		temp;
	t_intl	*anchor;

	anchor = (*list_b);
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

void	rra(t_intl **list)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*list);
	tmp = (*list);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*list);
	(*list) = last;
	tmp->next = NULL;
	ft_printf("rra\n");
}
