/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:57:53 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/11 11:07:56 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_list **topfrom, t_list **topto)
{
	t_list	*tmp;

	if (!topfrom || !(*topfrom))
		return ;
	tmp = (*topfrom)->next;
	ft_lstadd_front(topto, *topfrom);
	*topfrom = tmp;
}

void	ft_pa(t_list **tb, t_list **ta)
{
	ft_printf("pa\n");
	ft_push(tb, ta);
}

void	ft_pb(t_list **ta, t_list **tb)
{
	ft_printf("pb\n");
	ft_push(ta, tb);
}
