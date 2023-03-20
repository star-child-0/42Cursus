/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:31:55 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/20 18:01:10 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov(t_intl **list_a, t_intl **list_b)
{
	int	*mov_a;
	int	*mov_b;
	int	bp;
	int	len;

	len = tintl_length(list_b);
	while (len--)
	{
		mov_a = ft_mov_a(list_a, list_b, tintl_length(list_b));
		mov_b = ft_mov_b(tintl_length(list_b));
		bp = find_best_pos(find_best_mov(mov_a, mov_b, tintl_length(list_b)),
				tintl_length(list_b));
		if (mov_a[bp] >= 0 && mov_b[bp] >= 0)
			mov_plusplus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] >= 0 && mov_b[bp] <= 0)
			mov_plusminus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] <= 0 && mov_b[bp] >= 0)
			mov_minusplus(list_a, list_b, mov_a[bp], mov_b[bp]);
		else if (mov_a[bp] <= 0 && mov_b[bp] <= 0)
			mov_minusminus(list_a, list_b, mov_a[bp], mov_b[bp]);
		//mov_reorder(list_a);
		free(mov_a);
		free(mov_b);
	}
}

void	mov_plusplus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a && b)
	{
		rr(list_a, list_b);
		a--;
		b--;
	}
	while (a-- > 0)
		ra(list_a);
	while (b-- > 0)
		rb(list_b);
	pa(list_b, list_a);
}

void	mov_minusminus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a && b)
	{
		rrr(list_a, list_b);
		a++;
		b++;
	}
	while (a++ < 0)
		rra(list_a);
	while (b++ < 0)
		rrb(list_b);
	pa(list_b, list_a);
}

void	mov_plusminus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a--)
		ra(list_a);
	while (b++ < 0)
		rrb(list_b);
	pa(list_b, list_a);
}

void	mov_minusplus(t_intl **list_a, t_intl **list_b, int a, int b)
{
	while (a++ < 0)
		rra(list_a);
	while (b--)
		rb(list_b);
	pa(list_b, list_a);
}
