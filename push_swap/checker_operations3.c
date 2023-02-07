/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/07 19:27:26 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_rrb(t_intl **list)
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
}

void	do_rrr(t_intl **list_a, t_intl **list_b)
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
	do_rrr_2(list_b);
}

void	do_rrr_2(t_intl **list_b)
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
