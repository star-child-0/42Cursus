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

void	size_5_algorithm(int argc, t_intl **list_a, t_intl **list_b)
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
	if (argc == 4)
	{
		if (list_biggest(list_a) == (*list_a)->content)
			ra(list_a);
		return ;
	}
	size_5_algorithm2(list_a, list_b);
}

void	size_5_algorithm2(t_intl **list_a, t_intl **list_b)
{
	if ((*list_a)->content == list_biggest(list_a))
	{
		if (list_smallest(list_a) > (*list_b)->content)
		{
			ra(list_a);
			pa(list_b, list_a);
		}
		else
		{
			pa(list_b, list_a);
			ra(list_a);
			ra(list_a);
		}
	}
	else if ((*list_b)->content < list_smallest(list_a))
		pa(list_b, list_a);
}

// 1 3 4 6 2 5 -> ra		5 1 2 3 6 4 -> pb
// 3 4 6 2 5 1 -> ra		
// 4 6 2 5 1 3 -> ra
// 6 2 5 1 3 4 -> ra, pb
// 5 1 3 4 6, 2 -> pb
// 1 3 4 6, 5 2
void	size_100_algorithm(t_intl **list_a, t_intl **list_b)
{
	while (!is_list_ordered(list_a))
	{
		break ;
	}

	list_print(list_a);
	list_print(list_b);
	free_list(list_a);
	free_list(list_b);
}

void	size_500_algorithm(t_intl **list_a, t_intl **list_b)
{
	free_list(list_a);
	list_b = NULL;
}
