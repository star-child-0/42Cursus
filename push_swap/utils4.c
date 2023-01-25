/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:14:16 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/25 20:00:14 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simplify_list2(t_intl **list, int *orig)
{
	t_intl	*tmp;
	int		max;
	int		i;

	tmp = (*list);
	max = list_biggest(list);
	if (max < list_smallest(list) * -1)
		max = list_smallest(list) * -1;
	while (tmp)
	{
		i = -1;
		while (orig[++i])
		{
			if (tmp->content == orig[i])
			{
				tmp->content = i;
				orig[i] = max + 1;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(orig);
}

int	has_list_neg(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->content < 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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

int	*order_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	t;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	return (arr);
}
