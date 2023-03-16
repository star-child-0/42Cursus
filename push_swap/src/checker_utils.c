/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:52:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/16 19:06:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_repetition_c(int argc, char *argv[])
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

int	argv_check_c(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (!check_repetition_c(argc, argv) || argc == 1)
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

t_intl	*ft_push_c(int content)
{
	t_intl	*new;

	new = (t_intl *)malloc(sizeof(t_intl));
	new->content = content;
	new->next = NULL;
	return (new);
}

int	stackify_c(t_intl **list, int argc, char *argv[])
{
	int		i;
	t_intl	*node;

	node = (t_intl *) malloc(sizeof(t_intl));
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
		(*list)->next = ft_push_c(ft_atoi(argv[i]));
		(*list) = (*list)->next;
	}
	(*list) = node;
	return (1);
}

void	tintl_free_c(t_intl **list)
{
	t_intl	*tmp;

	tmp = (*list)->next;
	while (tmp)
	{
		(*list)->next = tmp->next;
		free(tmp);
		tmp = (*list)->next;
	}
}
