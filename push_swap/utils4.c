/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:03:50 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/21 20:04:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_ordered_chunk_size(t_intl **list)
{
	t_intl	*tmp;
	int		size;
	int		tot;

	size = 1;
	tot = 1;
	tmp = (*list);
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			size++;
		else
		{
			if (size > tot)
				tot = size;
			size = 1;
		}
		tmp = tmp->next;
	}
	return (tot);
}
