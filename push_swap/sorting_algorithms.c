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

void	size_3_algorithm(t_intl *list)
{
	if (FIRST > SECOND && SECOND < THIRD && FIRST < THIRD)
		sa(list);
	else if (FIRST > SECOND && SECOND > THIRD && FIRST > THIRD)
	{
		sa(list);
		rra(list);
	}
	else if (FIRST > SECOND && SECOND < THIRD && FIRST > THIRD)
		ra(list);
	else if (FIRST < SECOND && SECOND > THIRD && FIRST < THIRD)
	{
		sa(list);
		ra(list);
	}
	else if (FIRST < SECOND && SECOND > THIRD && FIRST > THIRD)
		rra(list);
}

void	size_5_algorithm(t_intl *list_a)
{
	t_intl	*list_b;
	
	list_b = NULL;	
	pb(list_a, list_b);
	pb(list_a, list_b);
	size_3_algorithm(list_a);
	pa(list_b, list_a);
	ra(list_a);
	pa(list_b, list_a);
}
