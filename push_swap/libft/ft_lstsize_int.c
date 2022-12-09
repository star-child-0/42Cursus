/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:52:39 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/09 18:52:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_int(t_intl *lst)
{
	int		k;
	t_intl	*temp;

	k = 0;
	temp = lst;
	while (lst)
	{
		lst = lst->next;
		k++;
	}
	return (k);
}
