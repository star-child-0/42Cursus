/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:18 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_rb(t_intl **list)
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

void	do_rra(t_intl **list)
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
