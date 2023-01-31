/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_issorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:10:48 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 12:10:59 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lst_issorted(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			if (*((int *)(lst->content)) < *((int *)(lst->next->content)))
				lst = lst->next;
			else
				return (0);
		}
	}
	return (1);
}
