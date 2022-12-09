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

t_intl	*size_3_algorithm(t_intl *list)
{
	if (FIRST > SECOND && SECOND < THIRD && FIRST < THIRD)
		sa(list);
	else if (FIRST > SECOND && SECOND > THIRD && FIRST > THIRD)
	{
		sa(list);
		list = rra(list);
	}
	else if (FIRST > SECOND && SECOND < THIRD && FIRST > THIRD)
		ra(list);
	else if (FIRST < SECOND && SECOND > THIRD && FIRST < THIRD)
	{
		sa(list);
		ra(list);
	}
	else if (FIRST < SECOND && SECOND > THIRD && FIRST > THIRD)
		list = rra(list);
	return (list);
}

//2 3 5 4 1 -> pb
//3 5 4 1, 2 -> pb
//---size 3 alg---//
//5 4 1, 3 2 -> sa
//4 5 1, 3 2 -> rra
//---size 3 alg---//
//1 4 5, 3 2 -> ra
//4 5 1, 3 2 -> pa

//3 4 5 1, 2 -> pa
//2 3 4 5 1 -> rra
//1 2 3 4 5
void	size_5_algorithm(int argc, t_intl *list_a, t_intl *list_b)
{
	t_intl	*temp;
	
	temp = list_a;
	if (argc == 5)
	{
		list_a = pb(list_a, list_b);
		list_b = temp;
	}
	temp = list_a;
	list_a = pb(list_a, list_b);
	list_b = temp;
	list_a = size_3_algorithm(list_a);
	if (list_b->content < list_b->next->content)
		sb(list_b);
	while (list_b)
	{
		if (list_b->content > list_a->content
			&& list_b->content < list_a->next->content)
		{
			ra(list_a);
			list_b = pa(list_b, list_a);
		}
		else if (list_b->content > ft_lstlast_int(list_a)->content
			&& list_b->content < list_a->content)
			list_b = pa(list_b, list_a);
		else
			list_a = rra(list_a);
	}
	ft_printf("list_a: ");
	list_output(list_a);
}
