/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:01:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/20 18:28:41 by anvannin         ###   ########.fr       */
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
	while (tintl_length(list_a) > 3)
	{
		if ((*list_a)->content == tintl_smallest(list_a)
			|| (*list_a)->content == tintl_biggest(list_a))
			pb(list_a, list_b);
		else
			ra(list_a);
	}	
	if (!is_tintl_ordered(list_a))
		size_3_algorithm(list_a);
	if ((*list_b)->next && (*list_b)->content < (*list_b)->next->content)
		sb(list_b);
	pa(list_b, list_a);
	if (argc == 4)
	{
		if (tintl_biggest(list_a) == (*list_a)->content)
			ra(list_a);
		return ;
	}
	size_5_algorithm2(list_a, list_b);
}

void	size_5_algorithm2(t_intl **list_a, t_intl **list_b)
{
	if ((*list_a)->content == tintl_biggest(list_a))
	{
		if (tintl_smallest(list_a) > (*list_b)->content)
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
	else if ((*list_b)->content < tintl_smallest(list_a))
		pa(list_b, list_a);
}

void	radix_sort(t_intl **list_a, t_intl **list_b)
{
	int	i;
	int	j;
	int	lb;

	simplify_list(list_a);
	j = 0;
	while (j < bin_mag(tintl_biggest(list_a)))
	{
		lb = 1;
		i = tintl_length(list_a) + 1;
		while (--i)
		{
			if (((*list_a)->content >> j & 1) % 2 == 0)
			{
				pb(list_a, list_b);
				lb ++;
			}
			else
				ra(list_a);
		}
		i = 0;
		while (++i < lb)
			pa(list_b, list_a);
		j++;
	}
}

/*
With 100 numbers, we can get

5 points if the size of the list of instructions is less than 700

4 points if the size of the list of instructions is less than 900

3 points if the size of the list of instructions is less than 1100

2 points if the size of the list of instructions is less than 1300

1 points if the size of the list of instructions is less than 1500

With 500 numbers, we can get

5 points if the size of the list of instructions is less than 5500

4 points if the size of the list of instructions is less than 7000

3 points if the size of the list of instructions is less than 8500

2 points if the size of the list of instructions is less than 10000

1 points if the size of the list of instructions is less than 11500
*/
void	size_any_algorithm(t_intl **list_a, t_intl **list_b)
{
	lis_algorithm(list_a, list_b);
	mov(list_a, list_b);
}
