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

void	size_3_algorithm(t_list *list)
{
	t_list	*anchor;
	
	anchor = list;
	while (!is_list_ordered(list))
	{
		anchor = list;
		if (FIRST > SECOND && SECOND < THIRD)
		{
			if (FIRST > THIRD)
				ra(list);
			else
				sa(list);
		}
		else if (FIRST < SECOND)
			sa(list);
		else
			rra(list);
	}
	anchor = list;
}

void	size_5_algorithm(t_list *list)
{
	
}

void	size_100_algorithm(t_list *list)
{
	
}

void	size_500_algorithm(t_list *list)
{
	
}
