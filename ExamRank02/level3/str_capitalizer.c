/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:35:42 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/10 20:05:50 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while(i++ < argc - 1)
	{
		j = -1;
		while(argv[i][++j])
		{
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z' && (j == 0
				|| argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t'
				|| argv[i][j - 1] == '\n' || argv[i][j - 1] == '\v'
				|| argv[i][j - 1] == '\f' || argv[i][j - 1] == '\r'))
				argv[i][j] -= 32;
			else if (argv[i][j] >= 'A' && argv[i][j] <= 'Z' && j > 0
				&& !(argv[i][j - 1] == ' ' || argv[i][j - 1] == '\t'
				|| argv[i][j - 1] == '\n' || argv[i][j - 1] == '\v'
				|| argv[i][j - 1] == '\f' || argv[i][j - 1] == '\r'))
				argv[i][j] += 32;
			write(1, &argv[i][j], 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}
