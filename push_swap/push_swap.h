/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 20:47:34 by anvannin          #+#    #+#             */
/*   Updated: 2022/11/24 20:47:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// to be deleted, damn you Norminette

# define FIRST list->content
# define SECOND list->next->content
# define THIRD list->next->next->content

// check input is correct and put it into a linked-list
int		argv_check(int argc, char *argv[]);
int		check_repetition(int argc, char *argv[]);
int		stackify(t_intl *list, int argc, char *argv[]);

// utils 2
int		is_list_ordered(t_intl *list);
void	list_output(t_intl *list);

// depending on list size, the sort logic is different
void	list_size(int argc, t_intl *list_a, t_intl *list_b);
t_intl	*size_3_algorithm(t_intl *list);
void	size_5_algorithm(int argc, t_intl *list_a, t_intl *list_b);

// p operations
t_intl	*pa(t_intl *list_b, t_intl *list_a);
t_intl	*pb(t_intl *list_a, t_intl *list_b);

// r operations
void	ra(t_intl *list);
t_intl	*rra(t_intl *list);

// s operations
void	sa(t_intl *list);
void	sb(t_intl *list);

// finish
void	free_list(t_intl *list);

#endif
