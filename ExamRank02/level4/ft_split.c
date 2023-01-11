/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:33:43 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/11 20:11:41 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	if (!str[i])
		return (0);
	while (is_space(str[i]))
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (is_space(str[i]) && str[i - 1] && str[i + 1]
			&& !is_space(str[i + 1]))
			n++;
		i++;
	}
	return (n);
}

char    **ft_split(char *str)
{
	int		i;
	int		w;
	int		wl;
	char	**mx;
	
	i = 0;
	w = -1;
	mx = (char **)malloc(word_count(str) * sizeof(char *));
	while (++w < word_count(str))
	{
		wl = 0;
		while (is_space(str[i]))
			i++;
		while (!is_space(str[i]))
		{
			wl++;		
			i++;
		}
		mx[w] = (char *)malloc((wl - 1) * sizeof(char));
	}
	i = 0;
	w = 0;
	while (str[i])
	{
		wl = 0;
		while (is_space(str[i]))
			i++;
		while (!is_space(str[i]) && str[i])
		{			
			mx[w][wl] = str[i];
			// write(1, &mx[w][wl], 1);
			i++;
			wl++;
		}
		// write(1, "\n", 1);
		w++;
	}
	return (mx);
}

int main(void){
	#include <stdio.h>

	ft_split("Hello World");
}