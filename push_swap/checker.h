/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:49:53 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/06 19:07:52 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

//	utils_checker
int	argv_check_c(int argc, char *argv[]);
int	check_repetition_c(int argc, char *argv[]);
t_intl	*ft_push(int content);
int	stackify_c(t_intl **list, int argc, char *argv[]);
int	is_list_ordered_c(t_intl **list);

//	utils_checker2
int	list_lenght_c(t_intl **list);



#endif
