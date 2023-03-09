/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/09 17:52:33 by anvannin         ###   ########.fr       */
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
	while (++i < len / 2 + 1)
		mov_b[i] = i;
	j = (i - 2) * -1;
	while (i < j)
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
		if (tmp_b->content < list_smallest(list_a)
			|| tmp_b->content > list_biggest(list_a))
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

// make re && ./push_swap 48 4 8 2 9 12 1 43 42 47 31 -20 7 13 3 10

// ft_printf("mov_a:\tmov_b:\tbest:\n");
// for (int k = 0; k < list_length(list_b); k++)
// 	ft_printf("  %d\t  %d\t  %d\n", mov_a[k], mov_b[k], best[k]);
void	mov(t_intl **list_a, t_intl **list_b)
{
	int	*mov_a;
	int	*mov_b;
	int	*best;
	int	i;
	int	small;
	int	small_i;
	int	len;

	len = list_length(list_b);
	while (len > 0)
	{
		mov_b = ft_mov_b(len);
		mov_a = ft_mov_a(list_a, list_b, len);
		best = find_best_mov(mov_a, mov_b, len);

		// ft_printf("mov_a:\tmov_b:\tbest:\n");
		// for (int k = 0; k < list_length(list_b); k++)
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
		ft_printf("small: %d, small_i: %d\n", small, small_i);
		
		int	x = mov_a[small_i];
		int	y = mov_b[small_i];
		
		// ft_printf("x: %d, y: %d\n", x, y);
		
		while (small_i > 0)
		{
			ft_printf("small_i: %d\n", small_i);
			if (mov_a[small_i] > 0 && mov_b[small_i] > 0)
				rr(list_a, list_b);
			else if (mov_a[small_i] < 0 && mov_b[small_i] < 0)
				rrr(list_a, list_b);
			else if (mov_a[small_i] > 0 && mov_b[small_i] < 0)
				ra(list_a);
			else
				rb(list_b);
			
			x--;
			y--;
			small_i--;
		}
		pa(list_b, list_a);
		
		free(best);
		free(mov_a);
		free(mov_b);
		
		len--;
	}
}
