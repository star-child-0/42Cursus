/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:30:58 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/22 21:43:01 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0 4 12 2 10 6 9 13 3 11 7 15
// lis: 0 2 6 9 13 15
int	*lis_algorithm(t_intl **list)
{
	int		i;
	int		j;
	int		*len;
	int		*arr;
	t_intl	*tmp;

	i = -1;
	tmp = (*list);
	arr = (int *)malloc(sizeof(int) * list_lenght(list));
	len = (int *)malloc(sizeof(int) * list_lenght(list));
	while (++i < list_lenght(list))
	{
		len[i] = 1;
		arr[i] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (++i < list_lenght(list))
	{
		j = -1;
		while (++j < i)
			if (arr[j] <= arr[i] && len[j] + 1 > len[i])
				len[i] = len[j] + 1;
	}
	return (len);
}
