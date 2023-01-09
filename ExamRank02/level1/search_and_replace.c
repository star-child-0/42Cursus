/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:08:12 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/09 18:45:54 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int char_in_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (1);
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 4 || str_len(argv[2]) != 1 || str_len(argv[3]) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (char_in_str(argv[1], argv[2][0]))
	{
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == argv[2][0])
				argv[1][i] = argv[3][0];
			i++;
		}
	}
	write(1, argv[1], str_len(argv[1]));
	write(1, "\n", 1);
	return (0);
}
