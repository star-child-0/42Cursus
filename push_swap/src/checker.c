/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:26 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 19:06:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_move_r(char *mov, t_intl **list_a, t_intl **list_b)
{
	if (!ft_strncmp(mov, "rra", 3))
		do_rra(list_a);
	else if (!ft_strncmp(mov, "rrb", 3))
		do_rrb(list_b);
	else if (!ft_strncmp(mov, "rrr", 3))
	{
		do_rra(list_a);
		do_rrb(list_b);
	}
	else if (!ft_strncmp(mov, "ra", 2))
		do_ra(list_a);
	else if (!ft_strncmp(mov, "rb", 2))
		do_rb(list_b);
	else if (!ft_strncmp(mov, "rr", 2))
	{
		do_ra(list_a);
		do_rb(list_b);
	}
}

void	exec_move(char *mov, t_intl **list_a, t_intl **list_b)
{
	if (!ft_strncmp(mov, "sa", 2))
		do_sa(list_a);
	else if (!ft_strncmp(mov, "sb", 2))
		do_sb(list_b);
	else if (!ft_strncmp(mov, "ss", 2))
	{
		do_sa(list_a);
		do_sb(list_b);
	}
	else if (!ft_strncmp(mov, "pa", 2))
		do_pa(list_b, list_a);
	else if (!ft_strncmp(mov, "pb", 2))
		do_pb(list_a, list_b);
	else
		exec_move_r(mov, list_a, list_b);
}

void	read_moves(t_intl **list_a, t_intl **list_b)
{
	char	*mov;

	while (1)
	{
		mov = get_next_line(0);
		if (!mov)
			return ;
		exec_move(mov, list_a, list_b);
	}
}

int	main(int argc, char *argv[])
{
	t_intl	*list_a;
	t_intl	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc == 1 && !argv)
		return (0);
	if (!argv_check_c(argc, argv) || !stackify_c(&list_a, argc, argv))
	{
		ft_putstr("Error\n");
		return (0);
	}
	read_moves(&list_a, &list_b);
	if (is_tintl_ordered_c(&list_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	tintl_free_c(&list_a);
	return (0);
}
