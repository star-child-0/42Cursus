/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:46 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/01 19:11:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_biggest(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = tmp->content;
	while (tmp)
	{
		if (tmp->content > n)
			n = tmp->content;
		tmp = tmp->next;
	}
	return (n);
}

int	list_smallest(t_intl **list)
{
	t_intl		*tmp;
	int			n;

	tmp = (*list);
	n = tmp->content;
	while (tmp)
	{
		if (tmp->content < n)
			n = tmp->content;
		tmp = tmp->next;
	}
	return (n);
}

int	list_lenght(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = 1;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

void	free_list(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list)->next;
	while (tmp)
	{
		(*list)->next = tmp->next;
		free(tmp);
		tmp = (*list)->next;
	}
}

void	simplify_list(t_intl **list)
{
	t_intl	*tmp;
	int		*orig;
	int		i;

	orig = (int *)malloc(sizeof(int) * list_lenght(list));
	i = -1;
	tmp = (*list);
	while (++i < list_lenght(list))
	{
		orig[i] = tmp->content;
		tmp = tmp->next;
	}
	orig = order_arr(orig, list_lenght(list));
	simplify_list2(list, orig);
}
