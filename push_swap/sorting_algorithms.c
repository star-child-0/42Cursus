/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:01:50 by anvannin          #+#    #+#             */
/*   Updated: 2022/11/24 21:01:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_3_algorithm(t_intl **list)
{
	if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content < (*list)->next->next->content)
		sa(list);
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->content > (*list)->next->next->content)
	{
		sa(list);
		rra(list);
	}
	else if ((*list)->content > (*list)->next->content
		&& (*list)->next->content < (*list)->next->next->content
		&& (*list)->content > (*list)->next->next->content)
		ra(list);
	else if ((*list)->content < (*list)->next->content
		&& (*list)->next->content > (*list)->next->next->content
		&& (*list)->content < (*list)->next->next->content)
	{
		sa(list);
		ra(list);
	}
	else
		rra(list);
}

void	size_5_algorithm(t_intl **list_a, t_intl **list_b)
{
	while (list_lenght(list_a) > 3)
	{
		if ((*list_a)->content == list_smallest(list_a)
			|| (*list_a)->content == list_biggest(list_a))
			pb(list_a, list_b);
		else
			ra(list_a);
	}
	if (!is_list_ordered(list_a))
		size_3_algorithm(list_a);
	if ((*list_b)->content < (*list_b)->next->content)
		sb(list_b);
	pa(list_b, list_a);
	if ((*list_a)->content == list_biggest(list_a))
	{
		ra(list_a);
		pa(list_b, list_a);
	}
	else if ((*list_b)->content < list_smallest(list_a))
		pa(list_b, list_a);
	else
	{
		ra(list_a);
		pa(list_b, list_a);
	}
}
