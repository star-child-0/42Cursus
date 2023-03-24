/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/24 20:42:35 by anvannin         ###   ########.fr       */
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
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%c   ft_printf:\t\t %c\n", 42) - 3, printf("%%c   printf:\t\t %c\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-c  ft_printf:\t\t %-c\n", 'a') - 3,printf("%%-c  printf:\t\t %-c\n", 'a'));

	printf("hfiosasdhopspojcopsd % 8s hfiosasdsjopspojcopsd\n", "hello");
	printf("hfiosasdhopspojcopsd %.8s hfiosasdsjopspojcopsd\n", "hello");
	printf("hfiosasdhopspojcopsd %-8s hfiosasdsjopspojcopsd\n", "hello");
	printf("hfiosasdhopspojcopsd %.8d hfiosasdsjopspojcops\n", 42);
	printf("hfiosasdhopspojcopsd %-8d hfiosasdsjopspojcops\n", 42);
	printf("hfiosasdhopspojcopsd %8d hfiosasdhjopspojcopsd", 42);

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", 42) - 3, printf("%%-di printf:\t\t %-d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%-di ft_printf:\t\t %-d\n\n", -42) - 3,printf("%%-di printf:\t\t %-d\n", -42));

	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", 42) - 3, printf("%%.di printf:\t\t %.d\n", 42));
	// printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", -42) - 3,printf("%%.di printf:\t\t %.d\n", -42));

	// printf("ret ft_printf: %d\tret printf: %d\n", ft_printf("%%%% ft_printf:\t\t %%\n") - 3, printf("%%%% printf:\t\t %%\n"));
	return (0);
}
