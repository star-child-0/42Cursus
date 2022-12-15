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
	t_intl	*list_a;
	t_intl	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc <= 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (argv_check(argc, argv) && stackify(&list_a, argc, argv))
	{
		list_size(argc - 1, &list_a, &list_b);
		list_print(&list_a);
		free_list(&list_a);
	}
	else
		ft_putstr("Error\n");
	return (0);
}
