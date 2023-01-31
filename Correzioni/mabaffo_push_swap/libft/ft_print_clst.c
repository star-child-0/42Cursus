/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_clst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:01:17 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/06 16:14:38 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_clst(t_list *lst)
{
	int	i;

	if (!lst)
	{
		ft_printf("(Null)\n");
		return (0);
	}
	i = 1;
	ft_printf("%d ", *((char *)lst->content));
	while (lst->next)
	{
		lst = lst->next;
		ft_printf("%d ", *((char *)lst->content));
		i++;
	}
	ft_printf("\n");
	return (i);
}
