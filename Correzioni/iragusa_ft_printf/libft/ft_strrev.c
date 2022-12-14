/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:06:06 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/12 17:06:09 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strrev(char *str, int j)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < --j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}
