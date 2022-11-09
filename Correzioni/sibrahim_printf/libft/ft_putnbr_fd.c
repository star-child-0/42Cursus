/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:26 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/20 13:20:27 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_and_print(char arr[], long num, int i, int fd)
{
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	else if (num == 0)
	{
		write (fd, "0", 1);
	}
	while (num > 0)
	{
		arr[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &arr[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[10];
	int		i;
	long	num;

	num = 0;
	i = 0;
	num = n;
	ft_check_and_print(arr, num, i, fd);
}
