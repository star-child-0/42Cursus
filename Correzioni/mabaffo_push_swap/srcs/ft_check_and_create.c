/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 18:42:16 by mabaffo           #+#    #+#             */
/*   Updated: 2023/01/11 16:01:28 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

struct s_sup
{
	int	*tmp;
	int	pd;
};

static unsigned int	ft_bisex(int *array, int x, unsigned low, unsigned high)
{
	unsigned int	mid;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (array[mid] == x)
			return (mid);
		if (array[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (0);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*ft_bubble(int *arr, unsigned int size)
{
	int			*cccp;
	long int	i;
	long int	j;

	cccp = malloc(size * sizeof(int));
	if (!cccp)
		return (NULL);
	i = -1;
	while (++i < size)
		cccp[i] = arr[i];
	j = -1;
	while (++j < size - 1)
	{
		i = -1;
		while (++i < size - 1 - j)
		{
			if (cccp[i] > cccp[i + 1])
				ft_swap(&cccp[i], &cccp[i + 1]);
		}
	}
	i = -1;
	return (cccp);
}

t_list	*ft_check_and_create(int ac, char **av)
{
	int				*arr;
	struct s_sup	dhn;
	int				*srtd;
	t_list			*top;

	arr = ft_check_args(ac, av);
	ac -= 2;
	dhn.pd = ac + 1;
	srtd = ft_bubble(arr, ac + 1);
	dhn.tmp = malloc(sizeof(int));
	if (!dhn.tmp)
		return (NULL);
	*(dhn.tmp) = ft_bisex(srtd, arr[ac], 0, dhn.pd);
	top = ft_lstnew(dhn.tmp);
	while (--ac >= 0)
	{
		dhn.tmp = malloc(sizeof(int));
		if (!dhn.tmp)
			return (NULL);
		*(dhn.tmp) = ft_bisex(srtd, arr[ac], 0, dhn.pd);
		ft_lstadd_front(&top, ft_lstnew(dhn.tmp));
	}
	free(arr);
	free(srtd);
	return (top);
}
