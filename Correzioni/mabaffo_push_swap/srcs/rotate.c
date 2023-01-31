/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:29:41 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:47:04 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_list **top)
{
	t_list	*tmp;

	if (!top || !(*top) || !((*top)->next))
		return ;
	tmp = (*top)->next;
	(*top)->next = NULL;
	ft_lstadd_back(&tmp, *top);
	*top = tmp;
}

void	ft_ra(t_list **ta)
{
	ft_printf("ra\n");
	ft_rotate(ta);
}

void	ft_rb(t_list **tb)
{
	ft_printf("rb\n");
	ft_rotate(tb);
}

void	ft_rr(t_list **ta, t_list **tb)
{
	ft_printf("rr\n");
	ft_rotate(ta);
	ft_rotate(tb);
}
