/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:12:01 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/06 19:29:10 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_text(int pid, char *str)
{
	int			i;
	int			x;
	static int	check;

	i = -1;
	check = 0;
	while (str[++i])
	{
		x = 8;
		while (x--)
		{
			if (str[i] >> x & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		check++;
	}
	if (ft_strlen(str) == check)
		ft_printf("Message recieved from server\n");
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong input, insert PID and message\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_text(pid, argv[2]);
	return (0);
}
