/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 19:29:42 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
clear && gcc *.c && ./a.out
clear && gcc *.c && valgrind ./a.out
clear && gcc *.c && valgrind --leak-check=full ./a.out
*/
#include <stdio.h>
#include "ft_printf.h"
int	main(int argc, char **argv)
{
	printf("printf\t\t |% 10s|\n", "a");
	printf("printf\t\t |%10s| \n", "a");
	printf("printf\t\t |% s|\n", "a");
	
	ft_printf("ft_printf\t |% 10s|\n", "a");
	ft_printf("ft_printf\t |%10s| \n", "a");
	ft_printf("ft_printf\t |% s|\n", "a");
	

	// printf("--------- % 8s ---------\n", "hello");
	// printf("--------- %.8s ---------\n", "hello");
	// printf("--------- %-8s ---------\n", "hello");
	// printf("--------- %.8d ---------\n", 42);
	// printf("--------- %-8d ---------\n", 42);
	// printf("--------- %8d ---------", 42);

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", 42) - 3, printf("%%-di printf:\t\t %-d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", -42) - 3,printf("%%-di printf:\t\t %-d\n", -42));

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", 42) - 3, printf("%%.di printf:\t\t %.d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", -42) - 3,printf("%%.di printf:\t\t %.d\n", -42));
	return (0);
}
