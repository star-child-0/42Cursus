/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:41:19 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/14 18:33:08 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	f_cknorminette(t_list **ta, t_list **tb)
{
	ft_rotate(ta);
	ft_rotate(tb);
}

static void	ft_move(t_list **ta, t_list **tb, char *line)
{
	if (!ft_strcmp(line, "ra\n"))
		ft_rotate(ta);
	else if (!ft_strcmp(line, "rb\n"))
		ft_rotate(tb);
	else if (!ft_strcmp(line, "rr\n"))
		f_cknorminette(ta, tb);
	else if (!ft_strcmp(line, "rra\n"))
		ft_rrotate(ta);
	else if (!ft_strcmp(line, "rrb\n"))
		ft_rrotate(tb);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		ft_rrotate(ta);
		ft_rrotate(tb);
	}
	else if (!ft_strcmp(line, "sa\n"))
		ft_sab(*ta);
	else if (!ft_strcmp(line, "sb\n"))
		ft_sab(*ta);
	else if (!ft_strcmp(line, "pa\n"))
		ft_push(tb, ta);
	else if (!ft_strcmp(line, "pb\n"))
		ft_push(ta, tb);
}

static void	f_cknorminette2(t_list **ta, t_list **tb)
{
	if (!(*tb) && ft_lst_issorted(*ta))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(ta, &free);
	if (*tb)
		ft_lstclear(tb, &free);
}

int	main(int ac, char **av)
{
	t_list	*top_a;
	t_list	*top_b;
	char	*line;

	top_a = ft_check_and_create(ac, av);
	top_b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		else
		{
			ft_move(&top_a, &top_b, line);
			free(line);
		}
	}
	f_cknorminette2(&top_a, &top_b);
	return (0);
}
