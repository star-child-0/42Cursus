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

void	list_size(int argc, t_intl **list_a, t_intl **list_b)
{

	if (argc == 2 && (*list_a)->content > (*list_a)->next->content)
		sa(list_a);
	else if (argc == 3)
		size_3_algorithm(list_a);
	else if (argc >= 4 && argc <= 5)
		size_5_algorithm(argc, list_a, list_b);
}

int	is_list_ordered(t_intl **list)
{
	while (*list)
	{
		if ((*list)->content > (*list)->next->content)
			return (0);
	}
	return (1);
}

int	ft_lstsize_int(t_intl **lst)
{
	int		k;
	t_intl	*temp;

	k = 0;
	temp = (*lst);
	while (lst)
	{
		(*lst) = (*lst)->next;
		k++;
	}
	return (k);
}
