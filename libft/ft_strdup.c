/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:17:26 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:35:23 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_strlen(src) * sizeof(char));
	i = -1;
	while (src[++i] != '\0')
		dest[i] = src[i];
	return (dest);
}
