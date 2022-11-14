/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:03:45 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/15 20:06:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tl;

	map = NULL;
	while (lst)
	{
		tl = ft_lstnew((*f)(lst->content));
		if (!tl)
			ft_lstdelone(lst, del);
		ft_lstadd_back(&map, tl);
		lst = lst->next;
	}
	return (map);
}
