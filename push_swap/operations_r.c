/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:04:39 by anvannin          #+#    #+#             */
/*   Updated: 2022/11/24 21:04:49 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_intl *list)
{
	int		temp;
	t_intl	*anchor;

	anchor = list;
	while (list)
	{
		if (list && list->next)
		{
			temp = FIRST;
			FIRST = SECOND;
			SECOND = temp;
		}
		list = list->next;
	}
	list = anchor;
	ft_printf("ra\n");
}

void	rra(t_intl *list)
{
	t_intl	*last;
	t_intl	*tmp;

	last = list;
	tmp = list;
	while (last->next)
	{
		tmp = last;
		last = last->next;
	}
	last->next = list;
	list = last;
	tmp->next = NULL;
	ft_printf("rra\n");
}
