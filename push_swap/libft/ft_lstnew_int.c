/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:13:05 by anvannin          #+#    #+#             */
/*   Updated: 2022/12/06 20:13:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_intl	*ft_lstnew_int(int content)
{
	t_intl	*new;

	new = (t_intl *)malloc(sizeof(t_intl));
	new->content = content;
	new->next = NULL;
	return (new);
}
