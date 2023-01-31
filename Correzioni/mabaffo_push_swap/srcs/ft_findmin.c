/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findmin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:40:31 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/10 20:16:20 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_findmin(t_list	*lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (*((int *)(min->content)) > *((int *)(lst->content)))
			min = lst;
		lst = lst->next;
	}
	return (min);
}
