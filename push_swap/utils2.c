/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:53:41 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/09 18:53:43 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_smallest_pos(t_intl **list)
{
	t_intl	*tmp;
	int		n;
	int		pos;

	tmp = (*list);
	n = tmp->content;
	while (tmp->next)
	{
		if (tmp->content < n)
		{
			n = tmp->content;
			pos = node_index(list, tmp);
		}
		tmp = tmp->next;
	}
	return (pos);
}

t_intl	*node_last(t_intl **lst)
{
	t_intl	*tmp;

	tmp = (*lst);
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	algorithm_selector(int argc, t_intl **list_a, t_intl **list_b)
{
	if (argc == 2 && (*list_a)->content > (*list_a)->next->content)
		sa(list_a);
	else if (argc == 3 && !is_list_ordered(list_a))
		size_3_algorithm(list_a);
	else if (argc >= 4 && argc <= 5 && !is_list_ordered(list_a))
		size_5_algorithm(list_a, list_b);
}

int	is_list_ordered(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list);
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	node_index(t_intl **list, t_intl *node)
{
	t_intl	*tmp;
	int		i;

	tmp = (*list);
	i = 0;
	while (tmp->next)
	{
		if (node == tmp)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
