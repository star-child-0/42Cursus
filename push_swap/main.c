/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:43:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/16 19:30:20 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc <= 1 || !argv_check(argc, argv) || !stackify(&list_a, argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	algorithm_selector(argc - 1, &list_a, &list_b);
	free_list(&list_a);
	return (0);
}
