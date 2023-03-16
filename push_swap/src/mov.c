/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 19:08:02 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_mov_b(int len)
{
	int	*mov_b;
	int	i;
	int	j;

	mov_b = (int *)malloc(sizeof(int) * len);
	i = -1;
	while (++i <= len / 2)
		mov_b[i] = i;
	j = (i - 2) * -1;
	if (len % 2 != 0)
		j--;
	while (i < len)
		mov_b[i++] = j++;
	return (mov_b);
}

void	mov_a_fill(t_intl **list_a, int *mov_a, t_intl *tmp_b, int i)
{
	int		m;
	t_intl	*tmp_a;

	m = 0;
	tmp_a = (*list_a);
	while (tmp_a->next && ++m)
	{
		mov_a[i] = m;
		if (tmp_b->content < tintl_smallest(list_a)
			|| tmp_b->content > tintl_biggest(list_a))
			mov_a[i] = 0;
		if (tmp_b->content > tmp_a->content
			&& tmp_b->content < tmp_a->next->content)
			break ;
		tmp_a = tmp_a->next;
	}
}

int	*ft_mov_a(t_intl **list_a, t_intl **list_b, int len)
{
	int		i;
	int		*mov_a;
	t_intl	*tmp_b;

	i = 0;
	tmp_b = (*list_b);
	mov_a = (int *)malloc(sizeof(int) * len);
	while (tmp_b)
	{
		mov_a_fill(list_a, mov_a, tmp_b, i);
		tmp_b = tmp_b->next;
		i++;
	}
	return (mov_a);
}

int	*find_best_mov(int *mov_a, int *mov_b, int len)
{
	int	*best;
	int	i;

	i = -1;
	best = (int *)malloc(sizeof(int) * len);
	while (++i < len)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0
			&& mov_a[i] > mov_b[i])
			best[i] = mov_a[i];
		else if (mov_a[i] >= 0 && mov_b[i] >= 0
			&& mov_a[i] < mov_b[i])
			best[i] = mov_b[i];
		else if (mov_a[i] < 0 && mov_b[i] < 0
			&& mov_a[i] < mov_b[i])
			best[i] = mov_a[i] * -1;
		else if (mov_a[i] < 0 && mov_b[i] < 0
			&& mov_a[i] > mov_b[i])
			best[i] = mov_b[i] * -1;
		else if (mov_a[i] >= 0 && mov_b[i] < 0)
			best[i] = mov_a[i] + (mov_b[i] * -1);
		else if (mov_a[i] < 0 && mov_b[i] >= 0)
			best[i] = mov_b[i] + (mov_a[i] * -1);
	}
	return (best);
}

int	find_best_pos(int *best, int len)
{
	int	i;
	int	small;
	int	small_i;

	i = 0;
	small = best[i];
	small_i = i;
	while (++i < len)
	{
		if (best[i] < small)
		{
			small = best[i];
			small_i = i;
		}
	}
	free(best);
	return (small_i);
}

// make re && ./push_swap 48 4 8 2 9 12 1 43 42 47 31 -20 7 13 3 10
/*
48 4 8 2 9 12 1 43 42 47 31 -20 7 13 3 10

6 8 3 1 2 9 7 4 10 5
*/

// ft_printf("mov_a:\tmov_b:\tbest:\n");
// for (int k = 0; k < tintl_length(list_b); k++)
// 	ft_printf("  %d\t  %d\t  %d\n", mov_a[k], mov_b[k], best[k]);
void	movv(t_intl **list_a, t_intl **list_b)
{
	int	*mov_a;
	int	*mov_b;
	int	*best;
	int	i;
	int	small;
	int	small_i;
	int	len;

	len = tintl_length(list_b);
	while (len > 0)
	{
		mov_b = ft_mov_b(len);
		mov_a = ft_mov_a(list_a, list_b, len);
		best = find_best_mov(mov_a, mov_b, len);

		// ft_printf("mov_a:\tmov_b:\tbest:\n");
		// for (int k = 0; k < tintl_length(list_b); k++)
		// 	ft_printf("  %d\t  %d\t  %d\n", mov_a[k], mov_b[k], best[k]);

		i = 0;
		small = best[0];
		while (i < len)
		{
			if (best[i] < small)
			{
				small = best[i];
				small_i = i;
			}
			i++;
		}

		int	x = mov_a[small_i];
		int	y = mov_b[small_i];

		while (small >= 0)
		{
			if (x == 0 && y < 0)
				rrb(list_b);
			else if (x > 0 && y > 0)
				rr(list_a, list_b);
			else if (x < 0 && y < 0)
				rrr(list_a, list_b);
			else if (x > 0 && y == 0)
			{
				while (x--)
					ra(list_a);
				break;
			}
			else if (x > 0 && y < 0)
			{
				rrb(list_b);
				ra(list_a);
			}
			else if (y < 0)
				rrb(list_b);
			else if ((*list_a)->content > (*list_b)->content
				&& (*list_b)->content > tintl_last(list_a))
				break ;
			else
				rb(list_b);

			x--;
			if (y > 0)
				y--;
			else if (y < 0)
				y++;
			small_i--;
			small--;
		}
		if ((*list_b)->content > (*list_a)->content
			&& (*list_b)->content < (*list_a)->next->content)
			ra(list_a);
		pa(list_b, list_a);

		if (!is_tintl_ordered(list_a))
		{
			int ls = tintl_smallest_pos(list_a);
			if (ls > tintl_length(list_a) / 2)
				while (ls-- && !is_tintl_ordered(list_a))
					rra(list_a);
			else
				while (ls-- && !is_tintl_ordered(list_a))
					ra(list_a);
		}

		free(best);
		free(mov_a);
		free(mov_b);

		len--;
	}
}

//--------------------------------------------------------------

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
		bp = find_best_pos(find_best_mov(mov_a, mov_b, tintl_length(list_b)), tintl_length(list_b));

		ft_printf("mov_a:\tmov_b:\n");
		for (int k = 0; k < tintl_length(list_b); k++)
			ft_printf("  %d\t  %d\n", mov_a[k], mov_b[k]);
		ft_printf("best_pos: %d\n", bp);

		free(mov_a);
		free(mov_b);
		break;
	}
	tintl_free(list_b);
}
