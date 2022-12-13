/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:32 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/13 18:55:34 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_text_send(int pid, char *str)
{
	int			i;
	int			x;
	static int	check = 0;

	x = 0;
	while (str[x])
	{
		i = 8;
		while (i--)
		{
			if (str[x] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		x++;
		check++;
	}
	if (ft_strlen(str) == check)
		write (1, "Message received from server\n", 29);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ft_text_send(pid, argv[2]);
	}
	else
		write (1, "Wrong input, insert PID and message\n", 36);
	return (0);
}
