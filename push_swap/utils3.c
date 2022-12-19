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
	t_intl	*tmp;
	int		n;

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
