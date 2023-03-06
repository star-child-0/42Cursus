/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/01 19:20:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_intl **list_b, t_intl **list_a)
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
	ft_printf("pa\n");
}

void	pb(t_intl **list_a, t_intl **list_b)
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
	ft_printf("pb\n");
}
