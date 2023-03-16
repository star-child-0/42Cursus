/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 19:06:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

//	checker
void	read_moves(t_intl **list_a, t_intl **list_b);
void	exec_move(char *mov, t_intl **list_a, t_intl **list_b);
void	exec_move_r(char *mov, t_intl **list_a, t_intl **list_b);

//	checker_utils
int		argv_check_c(int argc, char *argv[]);
int		check_repetition_c(int argc, char *argv[]);
t_intl	*ft_push_c(int content);
int		stackify_c(t_intl **list, int argc, char *argv[]);
void	tintl_free_c(t_intl **list);

//	checker_utils2
int		tintl_length_c(t_intl **list);
void	list_print_c(t_intl **list);
int		is_tintl_ordered_c(t_intl **list);

//	checker_operations.c
void	do_sa(t_intl **list);
void	do_sb(t_intl **list);
void	do_pa(t_intl **list_b, t_intl **list_a);
void	do_pb(t_intl **list_a, t_intl **list_b);
void	do_ra(t_intl **list);

//	checker_operations2.c
void	do_rb(t_intl **list);
void	do_rra(t_intl **list);
void	do_rrb(t_intl **list);

#endif
