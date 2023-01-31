/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:06:40 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:41:27 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_countbits(int num)
{
	int	nb;

	nb = 0;
	while (num)
	{
		num >>= 1;
		nb++;
	}
	return (nb);
}

void	ft_sort(t_list **ta, t_list **tb)
{
	int	size;
	int	i;
	int	nb;

	nb = ft_countbits(ft_lstsize(*ta) - 1);
	i = -1;
	while (++i < nb)
	{
		size = ft_lstsize(*ta);
		while (size)
		{
			if (!((*((unsigned int *)((*ta)->content)) >> i) & 1))
				ft_pb(ta, tb);
			else
				ft_ra(ta);
			size--;
		}
		size = ft_lstsize(*tb);
		while (size)
		{
			ft_pa(tb, ta);
			size--;
		}
	}
}
