/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:30:58 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/24 21:58:02 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_algorithm(t_intl **list_a, t_intl **list_b)
{
	int		i;
	int		j;
	int		*len;
	int		*arr;
	t_intl	*tmp;

	i = -1;
	tmp = (*list_a);
	arr = (int *)malloc(sizeof(int) * list_length(list_a));
	len = (int *)malloc(sizeof(int) * list_length(list_a));
	while (++i < list_length(list_a))
	{
		len[i] = 1;
		arr[i] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (++i < list_length(list_a))
	{
		j = -1;
		while (++j < i)
			if (arr[j] <= arr[i] && len[j] + 1 > len[i])
				len[i] = len[j] + 1;
	}
	get_lis_values(len, arr, list_a, list_b);
}

int	lis_size(int *len, int list_len)
{
	int	i;
	int	max;

	i = -1;
	max = INT_MIN;
	while (++i < list_len)
		if (len[i] > max)
			max = len[i];
	return (max);
}

void	free_arr(int *arr, int *len, int *lis)
{
	free(arr);
	free(len);
	free(lis);
}

int	number_in_array(int n, int *arr, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (arr[i] == n)
			return (1);
	return (0);
}

void	get_lis_values(int *len, int *arr, t_intl **list_a, t_intl **list_b)
{
	int	i;
	int	max;
	int	rem;
	int	*lis;

	i = list_length(list_a);
	max = lis_size(len, list_length(list_a));
	rem = list_length(list_a) - max;
	lis = (int *)malloc(sizeof(int) * max);
	while (--i >= 0)
		if (len[i] == max)
			lis[--max] = arr[i];
	while (max < rem)
	{
		if (is_list_ordered(list_a))
			break ;
		if (number_in_array((*list_a)->content, lis, rem))
			ra(list_a);
		else if (max ++ > INT_MIN)
			pb(list_a, list_b);
	}
	free_arr(arr, len, lis);
	if ((*list_a)->content > (*list_a)->next->content)
		ra(list_a);
}
