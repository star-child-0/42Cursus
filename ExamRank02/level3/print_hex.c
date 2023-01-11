/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:16:33 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/11 20:13:10 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
	int	i;
	int	n;
	
	n = 0;
	i = -1;
	while (str[++i] && str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[i] - '0';
	return (n);
}

void ft_putnbr_hex(int n)
{
	char	c;
	char	*hex;
	
	hex = "0123456789abcdef";
	c = hex[n % 16];
	if (n > 15)
		ft_putnbr_hex(n / 16);
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	if (argc != 2 || !(argv[1][0] >= '0' && argv[1][0] <= '9'))
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_putnbr_hex(ft_atoi(argv[1]));
	return (0);
}