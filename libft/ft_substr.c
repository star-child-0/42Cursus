/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:21:14 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:48:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*sub;

	i = 0;
	sub = (char *)malloc(len);
	while (i < start)
		i++;
	while (i < len)
	{
		sub[i] = s[i];
		i++;
	}
	return (sub);
}
