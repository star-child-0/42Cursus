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

# define FIRST list->content
# define SECOND list->next->content
# define THIRD list->next->next->content

// check input is correct and put it into a linked-list
int		argv_check(int argc, char *argv[]);
int		check_repetition(int argc, char *argv[]);
int		stackify(t_intl *list, int argc, char *argv[]);

// depending on list size, the sort logic is different
void	list_size(int argc, t_intl *list);
void	size_3_algorithm(t_intl *list);
void	size_5_algorithm(t_intl *list);
void	size_100_algorithm(t_intl *list);
void	size_500_algorithm(t_intl *list);
int		is_list_ordered(t_intl *list);

// p operations

// r operations
void	ra(t_intl *list);
void	rra(t_intl *list);

// s operations
void	sa(t_intl *list);

// finish
void	free_list(t_intl *list);

#endif
