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

void	size_5_algorithm(t_intl *list)
{
}

void	size_100_algorithm(t_intl *list)
{
}

void	size_500_algorithm(t_intl *list)
{
}
