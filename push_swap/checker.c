/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/06 19:07:31 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;
	// char	*str;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1 && !argv)
		return (0);
	if (!argv_check_c(argc, argv) && !stackify(&list_a, argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	//str = get_next_line(0);
	if (is_list_ordered_c(&list_a) && !list_lenght_c(&list_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
