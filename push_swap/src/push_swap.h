/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:34 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/19 19:16:45 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/libft.h"

// algorithm_selector.c
void	algorithm_selector(int argc, t_intl **list_a, t_intl **list_b);

// utils.c
int		stackify(t_intl **list, int argc, char *argv[]);
int		check_repetition(int argc, char *argv[]);
int		argv_check(int argc, char *argv[]);
void	simplify_list(t_intl **list);
void	simplify_list2(t_intl **list, int *orig);

// utils2.c
int		bin_mag(int n);
int		*order_arr(int *arr, int len);

// LIS algorithm
void	lis_algorithm(t_intl **list_a, t_intl **list_b);
int		lis_size(int *len, int list_len);
int		number_in_array(int n, int *arr, int len);
void	get_lis_values(int *len, int *arr, t_intl **list_a, t_intl **list_b);
void	reorder_lis(t_intl **list_a, int *arr, int *len, int *lis);

// mov.c
int		*ft_mov_b(int len);
int		*ft_mov_a(t_intl **list_a, t_intl **list_b, int len);
void	mov(t_intl **list_a, t_intl **list_b);
void	mov_a_fill(t_intl **list_a, int *mov_a, t_intl *tmp_b, int i);
int		*find_best_mov(int *mov_a, int *mov_b, int len);
int		find_best_pos(int *best, int len);

// exec_mov.c
void	mov(t_intl **list_a, t_intl **list_b);
void	mov_plusplus(t_intl **list_a, t_intl **list_b, int a, int b);
void	mov_minusminus(t_intl **list_a, t_intl **list_b, int a, int b);
void	mov_plusminus(t_intl **list_a, t_intl **list_b, int a, int b);
void	mov_minusplus(t_intl **list_a, t_intl **list_b, int a, int b);

// mov_reorder.c
void	mov_reorder(t_intl **list);

// sorting_algorithms.c
void	size_3_algorithm(t_intl **list);
void	size_5_algorithm(int argc, t_intl **list_a, t_intl **list_b);
void	size_5_algorithm2(t_intl **list_a, t_intl **list_b);
void	radix_sort(t_intl **list_a, t_intl **list_b);
void	size_any_algorithm(t_intl **list_a, t_intl **list_b);

// operations_p.c
void	pa(t_intl **list_b, t_intl **list_a);
void	pb(t_intl **list_a, t_intl **list_b);

// operations_r.c
void	ra(t_intl **list);
void	rb(t_intl **list);
void	rr(t_intl **list_a, t_intl **list_b);
void	rr_2(t_intl **list_b);
void	rra(t_intl **list);

// operations_r2.c
void	rrb(t_intl **list);
void	rrr(t_intl **list_a, t_intl **list_b);
void	rrr_2(t_intl **list_b);

// operations_s.c
void	sa(t_intl **list);
void	sb(t_intl **list);
void	ss(t_intl **list_a, t_intl **list_b);

#endif
