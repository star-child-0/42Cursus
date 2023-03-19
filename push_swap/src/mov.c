/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/19 18:04:33 by anvannin         ###   ########.fr       */
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
