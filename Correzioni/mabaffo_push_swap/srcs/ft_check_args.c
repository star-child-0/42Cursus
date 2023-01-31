/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:56:16 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/12 13:42:33 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_num(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (s[i] == '-')
		i++;
	len = ft_strlen(&s[i]);
	if (len == 0 || (i == 1 && s[i] == '0'))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	not_only_num(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_num(av[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	double_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (!ft_strcmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_check_args(int ac, char **av)
{
	if (ac < 2)
		exit(1);
	if (not_only_num(ac, av) || double_arg(ac, av))
		ft_puterror();
	return (ft_check_ints(ac, av));
}
