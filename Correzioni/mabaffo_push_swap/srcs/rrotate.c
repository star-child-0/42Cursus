/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:01:41 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/07 16:04:00 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_newlast(t_list *lst)
{
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_rrotate(t_list **top)
{
	t_list	*newlast;

	if (!top || !(*top) || !((*top)->next))
		return ;
	newlast = ft_newlast(*top);
	ft_lstadd_front(top, newlast->next);
	newlast->next = NULL;
}

void	ft_rra(t_list **ta)
{
	ft_printf("rra\n");
	ft_rrotate(ta);
}

void	ft_rrb(t_list **tb)
{
	ft_printf("rrb\n");
	ft_rrotate(tb);
}

void	ft_rrr(t_list **ta, t_list **tb)
{
	ft_printf("rrr\n");
	ft_rrotate(ta);
	ft_rrotate(tb);
}
