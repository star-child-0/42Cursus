/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbozzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:49:36 by mbozzi            #+#    #+#             */
/*   Updated: 2022/12/13 18:22:29 by mbozzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig)
{
	static int	i = 8;
	static char	c = 0;

	if (i--)
	{
		if (sig == SIGUSR1)
			c |= 1 << i;
	}
	if (i <= 0)
	{
		write (1, &c, 1);
		i = 8;
		c = 0;
	}
}

int	main(void)
{
	int		pid;
	char	*pidchar;
	int		i;

	pid = getpid();
	i = 0;
	pidchar = ft_itoa(pid);
	write (1, "The PID is: ", 12);
	while (pidchar[i])
	{
		write(1, &pidchar[i], 1);
		i++;
	}
	write (1, "\n", 1);
	free(pidchar);
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
	}
	return (0);
}
