/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:11:57 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/23 20:51:05 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// int	main(void)
// {
// 	if (signum == SIGUSR1)
// 		printf("Received SIGUSR1!\n");
// }

void	sig_handler(int signum)
{
	ft_printf("Signal %d caught!\n", signum);
	exit(1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);

	while (1)
	{
		ft_printf("Going to sleep for a second...\n");
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		sleep(1);
	}
	return (0);

	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return(0);
}
