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

void	pa(t_intl *list_a, t_intl *list_b)
{
	t_intl	*tmp;

	tmp = list_a;
	list_a = list_a->next;
	tmp->next = list_b;
	list_b = tmp;
	ft_printf("pa\n");
}

void	pb(t_intl *list_b, t_intl *list_a)
{
	t_intl	*tmp;

	tmp = list_b;
	list_b = list_b->next;
	tmp->next = list_a;
	list_a = tmp;
	ft_printf("pb\n");
}
