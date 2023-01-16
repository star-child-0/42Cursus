/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:34 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/16 21:07:35 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct i_list
{
	int				content;
	struct i_list	*next;
}t_intl;

// utils.c
void	list_print(t_intl **list);
t_intl	*ft_push(int content);
int		stackify(t_intl **list, int argc, char *argv[]);
int		check_repetition(int argc, char *argv[]);
int		argv_check(int argc, char *argv[]);

// utils2.c
int		list_smallest_pos(t_intl **list);
int		list_last(t_intl **lst);
void	algorithm_selector(int argc, t_intl **list_a, t_intl **list_b);
int		is_list_ordered(t_intl **list);
int		node_index(t_intl **list, t_intl *node);

// utils3.c
int		list_biggest(t_intl **list);
int		list_smallest(t_intl **list);
int		list_lenght(t_intl **list);
void	free_list(t_intl **list);

// utils4.c
int		bin_mag(int n);
int		is_list_revordered(t_intl **list);

// sorting_algorithms.c
void	size_3_algorithm(t_intl **list);
void	size_5_algorithm(int argc, t_intl **list_a, t_intl **list_b);
void	size_5_algorithm2(t_intl **list_a, t_intl **list_b);
void	radix_sort(t_intl **list_a, t_intl **list_b);

// operations_p.c
void	pa(t_intl **list_b, t_intl **list_a);
void	pb(t_intl **list_a, t_intl **list_b);

// operations_r.c
void	ra(t_intl **list);
void	rb(t_intl **list);
void	rra(t_intl **list);
void	rrb(t_intl **list);

// operations_s.c
void	sa(t_intl **list);
void	sb(t_intl **list);

#endif
