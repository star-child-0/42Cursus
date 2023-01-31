/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:35:56 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:46:30 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort3(t_list **ta)
{
	if (ft_lst_issorted(*ta))
		return ;
	if (*(int *)((*ta)->content) > *(int *)((*ta)->next->content))
	{
		if (*(int *)((*ta)->next->content)
				> *(int *)((*ta)->next->next->content))
		{
			ft_sa(*ta);
			ft_rra(ta);
		}
		else if (*(int *)((*ta)->content)
				> *(int *)((*ta)->next->next->content))
			ft_ra(ta);
		else
			ft_sa(*ta);
	}
	else if (*(int *)((*ta)->content) > *(int *)((*ta)->next->next->content))
		ft_rra(ta);
	else
	{
		ft_sa(*ta);
		ft_ra(ta);
	}
}
