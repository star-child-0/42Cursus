/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:46:51 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/09 19:16:04 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = -1;
	if (argc != 2)
		return (0);
	while (argv[1][++i])
	{
		j = -1;
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			while (++j < argv[1][i] - 'A')
				write(1, &argv[1][i], 1);
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			while (++j < argv[1][i] - 'a')
				write(1, &argv[1][i], 1);
		write(1, &argv[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
