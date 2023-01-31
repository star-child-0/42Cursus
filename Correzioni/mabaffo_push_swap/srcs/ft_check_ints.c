/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:23:32 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/10 21:43:17 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	f_err(int *arr)
{
	free(arr);
	ft_puterror();
}

int	*ft_check_ints(int ac, char **av)
{
	int			*arr;
	int			i;
	long int	tmp;

	arr = (int *) malloc(sizeof(int) * (ac - 1));
	if (!arr)
		ft_puterror();
	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) > 11)
			f_err(arr);
		tmp = ft_atoli(av[i]);
		if (tmp > (long int)(2147483647) || tmp < (long int)(-2147483648))
			f_err(arr);
		else
			arr[i - 1] = tmp;
		i++;
	}
	return (arr);
}
