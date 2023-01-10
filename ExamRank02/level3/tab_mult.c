/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:07:36 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/10 21:43:36 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include <stdio.h>

// man limits.h
int ft_atoi(char *str)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i] - '0';
	return (n);
}

void ft_putnbr(int n)
{
	int	c;
	c = (n % 10) + 48;
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int	n;
	int	i;
	char	c;

	if (argc != 2 || !(argv[1][0] >= '0' && argv[1][0] <= '9')
		|| ft_atoi(argv[1]) > INT_MAX / 9)
	{
		write(1, "\n", 1);
		return (0);
	}
	n = ft_atoi(argv[1]);
	i = 0;
	while (++i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(n * i);
		write(1, "\n", 1);
	}
	return (0);
}
