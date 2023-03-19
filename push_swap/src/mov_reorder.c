/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_reorder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:16:11 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/19 19:16:17 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_reorder(t_intl **list)
{
	if (tintl_smallest_pos(list) < tintl_length(list) / 2)
		while (!is_tintl_ordered(list))
			ra(list);
	else
		while (!is_tintl_ordered(list))
			rra(list);
}
