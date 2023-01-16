/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:14:16 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/16 21:07:35 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_mag(int n)
{
	int	m;

	m = 1;
	while (n > 1)
	{
		n /= 2;
		m++;
	}
	return (m);
}

int	is_list_revordered(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
