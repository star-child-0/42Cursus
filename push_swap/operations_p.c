/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:04:04 by anvannin          #+#    #+#             */
/*   Updated: 2022/11/24 21:04:29 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intl	*pa(t_intl *list_b, t_intl *list_a)
{
	t_intl	*tmp;
	
	tmp = list_b;	
	list_b = list_b->next;	
	tmp->next = list_a;
	list_a = tmp;
	
	ft_printf("list_a: ");
	list_output(list_a);
	ft_printf("list_b: ");
	list_output(list_b);

	ft_printf("pa\n");
	return (list_b);
}

t_intl	*pb(t_intl *list_a, t_intl *list_b)
{
	t_intl	*tmp;

	if (list_b != NULL)
	{
		tmp = list_a;
		list_a = list_a->next;
		tmp->next = list_b;
		list_b = tmp;
	}
	else
	{
		list_b = list_a;
		list_a = list_a->next;
		list_b->next = NULL;
	}
	ft_printf("pb\n");
	return (list_a);
}
