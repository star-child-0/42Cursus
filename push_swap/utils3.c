/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:44:46 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/14 20:44:48 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_intl	*node_biggest(t_intl **list)
{
	t_intl	*tmp;
	int		n;
	t_intl	*big;

	tmp = (*list);
	n = tmp->content;
	while (tmp->next)
	{
		if (tmp->content > n)
		{
			n = tmp->content;
			big = tmp;
		}
		tmp = tmp->next;
	}
	return (big);
}

int	list_lenght(t_intl **list)
{
	t_intl	*tmp;
	int		n;
	
	tmp = (*list);
	n = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		n++;
	}
	return (n);
}

t_intl	*node_smallest(t_intl **list)
{
	t_intl	*tmp;
	int		n;

	tmp = (*list);
	n = tmp->content;
	while (tmp->next)
	{
		if (tmp->content < n)
		{
			n = tmp->content;
		}
		tmp = tmp->next;
	}
	return (tmp);
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