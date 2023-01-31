/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ulst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:17:09 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/11 16:22:00 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ulst(t_list *lst)
{
	int	i;

	if (!lst)
	{
		ft_printf("(Null)\n");
		return (0);
	}
	i = 1;
	ft_printf("%u ", *((unsigned int *)lst->content));
	while (lst->next)
	{
		lst = lst->next;
		ft_printf("%u ", *((unsigned int *)lst->content));
		i++;
	}
	ft_printf("\n");
	return (i);
}
