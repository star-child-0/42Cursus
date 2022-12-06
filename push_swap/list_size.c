/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:12:35 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/06 20:12:37 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_size(int argc, t_intl *list)
{
	if (argc == 3)
		size_3_algorithm(list);
	else if (argc >= 4 && argc <= 5)
		size_5_algorithm(list);
	else if (argc >= 6 && argc <= 100)
		size_100_algorithm(list);
	else
		size_500_algorithm(list);
}
