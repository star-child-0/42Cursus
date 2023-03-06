/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:20:14 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/23 19:21:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_intl **list)
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
	ft_printf("rrb\n");
}

void	rrr(t_intl **list_a, t_intl **list_b)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*list_a);
	tmp = (*list_a);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*list_a);
	(*list_a) = last;
	tmp->next = NULL;
	rrr_2(list_b);
	ft_printf("rrr\n");
}

void	rrr_2(t_intl **list_b)
{
	t_intl	*last;
	t_intl	*tmp;

	last = (*list_b);
	tmp = (*list_b);
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = (*list_b);
	(*list_b) = last;
	tmp->next = NULL;
}
