/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:46:49 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:21:04 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_list	*top_a;
	t_list	*top_b;

	top_a = ft_check_and_create(ac, av);
	top_b = NULL;
	if (ft_lst_issorted(top_a))
	{
		ft_lstclear(&top_a, &free);
		return (0);
	}
	else if (ac == 3)
		ft_ra(&top_a);
	else if (ac == 4)
		ft_sort3(&top_a);
	else if (ac < 51)
		ft_lilsort(&top_a, &top_b);
	else
		ft_sort(&top_a, &top_b);
	ft_lstclear(&top_a, &free);
	return (0);
}
