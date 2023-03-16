/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:00:48 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 19:04:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackify(t_intl **list, int argc, char *argv[])
{
	int		i;
	t_intl	*node;

	node = (t_intl *) malloc(sizeof(t_intl));
	if (!node)
		return (0);
	node->content = ft_atol(argv[1]);
	node->next = NULL;
	(*list) = node;
	if (!list)
		return (0);
	i = 1;
	while (++i < argc)
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (0);
		(*list)->next = tintl_push(ft_atoi(argv[i]));
		(*list) = (*list)->next;
	}
	(*list) = node;
	return (1);
}

int	check_repetition(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
	}
	return (1);
}

int	argv_check(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (!check_repetition(argc, argv) || argc == 1)
		return (0);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != '\0')
			if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '+'
				|| argv[i][j] == '-'))
				return (0);
	}
	return (1);
}

void	simplify_list(t_intl **list)
{
	t_intl	*tmp;
	int		*orig;
	int		i;

	orig = (int *)malloc(sizeof(int) * tintl_length(list));
	i = -1;
	tmp = (*list);
	while (++i < tintl_length(list))
	{
		orig[i] = tmp->content;
		tmp = tmp->next;
	}
	orig = order_arr(orig, tintl_length(list));
	simplify_list2(list, orig);
}

void	simplify_list2(t_intl **list, int *orig)
{
	t_intl	*tmp;
	int		max;
	int		i;

	tmp = (*list);
	max = tintl_biggest(list);
	if (max < tintl_smallest(list) * -1)
		max = tintl_smallest(list) * -1;
	while (tmp)
	{
		i = -1;
		while (++i < tintl_length(list))
		{
			if (tmp->content == orig[i])
			{
				tmp->content = i;
				orig[i] = max + 1;
				break ;
			}
		}
		tmp = tmp->next;
	}
	free(orig);
}
