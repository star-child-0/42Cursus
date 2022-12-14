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

//2 3 5 4 1 -> pb
//3 5 4 1, 2 -> pb
//---size 3 alg---//
//5 4 1, 3 2 -> sa
//4 5 1, 3 2 -> rra
//---size 3 alg---//
//1 4 5, 3 2 -> sb
//1 4 5, 2 3 -> ra
//4 5 1, 2 3 -> pa
//2 4 5 1, 3 -> ra
//4 5 1 2, 3 -> pa
//3 4 5 1 2 -> rra
//2 3 4 5 1 -> rra
//1 2 3 4 5
void	size_5_algorithm(int argc, t_intl **list_a, t_intl **list_b)
{
	int	n;

	if (argc == 5)
		pb(list_a, list_b);
	pb(list_a, list_b);
	size_3_algorithm(list_a);
	if ((*list_b)->content > (*list_b)->next->content)
		sb(list_b);
	//-----------------------------------------------------
	ra(list_a);
	pa(list_b, list_a);
	ra(list_a);
	pa(list_b, list_a);
	//-----------------------------------------------------
	n = list_smallest(list_a);
	while (!is_list_ordered(list_a))
	{
		if (n > argc / 2)
			rra(list_a);
		else
			ra(list_a);
	}
}
