/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:16:24 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/08 21:21:56 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_mov_b(t_intl **list_b)
{
	int	*mov_b;
	int	i;
	int	j;

	mov_b = (int *)malloc(sizeof(int) * list_length(list_b));
	i = -1;
	while (++i < list_length(list_b) / 2 + 1)
		mov_b[i] = i;
	j = (i - 2) * -1;
	while (i < list_length(list_b))
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

int	*ft_mov_a(t_intl **list_a, t_intl **list_b)
{
	int		i;
	int		*mov_a;
	t_intl	*tmp_b;

	i = 0;
	tmp_b = (*list_b);
	mov_a = (int *)malloc(sizeof(int) * list_length(list_b));
	while (tmp_b)
	{
		mov_a_fill(list_a, mov_a, tmp_b, i);
		tmp_b = tmp_b->next;
		i++;
	}
	return (mov_a);
}

// make re && ./push_swap 48 4 8 2 9 12 1 43 42 47 31 -20 7 13 3 10

// ft_printf("mov_a:\tmov_b:\n");
// for (int k = 0; k < list_length(list_b); k++)
// 	ft_printf("  %d\t  %d\n", mov_a[k], mov_b[k]);
void	mov(t_intl **list_a, t_intl **list_b)
{
	int	*mov_a;
	int	*mov_b;

	mov_b = ft_mov_b(list_b);
	mov_a = ft_mov_a(list_a, list_b);
	free(mov_a);
	free(mov_b);
}
