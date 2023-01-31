/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ilst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:58:37 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/06 16:10:04 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ilst(t_list *lst)
{
	int	i;

	if (!lst)
	{
		ft_printf("(Null)\n");
		return (0);
	}
	i = 1;
	ft_printf("%d ", *((int *)lst->content));
	while (lst->next)
	{
		lst = lst->next;
		ft_printf("%d ", *((int *)lst->content));
		i++;
	}
	ft_printf("\n");
	return (i);
}
