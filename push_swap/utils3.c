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
