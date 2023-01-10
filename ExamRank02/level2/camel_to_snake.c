/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:39:50 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/10 18:39:52 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int		i;
	int		w;
	
	i = -1;
	w = 0;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][++i])
	{
		char c = argv[1][i];

		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			c += 32;
			write(1, "_", 1);
		}
		write(1, &c, 1);
	}
	return (0);
}