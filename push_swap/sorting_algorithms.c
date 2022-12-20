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

// 1 3 4|6 2 5 -> ra		5 1 2|3 6 4 -> rra			3 6 5 1 4 2
// ^----dal secondo in poi----^
// 3 4 6 2 5 1 -> ra, ra	4 5 1 2 3 6 -> rra, pb
// 6 2 5 1 3 4 -> pb pb		4 5 1 2 3, 6 -> ra, ra, pa		1 2 3 6, 4 5
// 5 1 3 4, 2 6 -> ra		6 1 2 3 4 5 -> ra
// 1 3 4 5, 6 2 			1 2 3 4 5 6
void	lis_algorithm(int argc, t_intl **list_a, t_intl **list_b)
{
	int	direction;

	// if pos di midnumber < argc / 2 
	direction = -1;
	ra(list_a); //non sempre (?)
	//else
	direction = 1;
	rra(list_a); //non sempre (?)
	while (!is_list_ordered(list_a))
	{
		if (direction == -1 && (*list_a)->content > list_last(list_a)
			&& (*list_a)->content < (*list_a)->next->content)
			ra(list_a);
		else if ((*list_a)->content > list_last(list_a)
			&& (*list_a)->content < (*list_a)->next->content)
			rra(list_a);
		else
			pb(list_a, list_b);
	}
	
	list_print(list_a);
	list_print(list_b);
	free_list(list_a);
	free_list(list_b);
}
