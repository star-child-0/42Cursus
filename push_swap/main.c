/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:43:33 by anvannin          #+#    #+#             */
/*   Updated: 2022/11/24 20:43:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		n;
	t_intl	*list_a;
	t_intl	*list_b;
	t_intl	*anchor;

	if (argc <= 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	list_b = NULL;
	n = ft_atoi(argv[1]);
	list_a = ft_lstnew_int(n);
	anchor = list_a;
	if (argv_check(argc, argv) && stackify(list_a, argc, argv) && list_a)
	{
		list_a = anchor;
		list_size(argc - 1, list_a, list_b);
		free_list(anchor);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
