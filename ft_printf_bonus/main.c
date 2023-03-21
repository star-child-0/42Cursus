/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:42:04 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/21 21:42:05 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
clear && gcc *.c && ./a.out
clear && gcc *.c && valgrind ./a.out
clear && gcc *.c && valgrind --leak-check=full ./a.out
*/
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%d   ft_printf:\t\t %d\n", 42) - 3, printf("%%d   printf:\t\t %d\n", 42));
	printf("ret ft_printf: %i\tret printf: %i\n\n", ft_printf("%%i   ft_printf:\t\t %i\n", 42) - 3, printf("%%i   printf:\t\t %i\n", 42));

	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%+di ft_printf:\t\t %+d\n", 42) - 3, printf("%%+di printf:\t\t %+d\n", 42));
	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%+di ft_printf:\t\t %+d\n", -42) - 3, printf("%%+di printf:\t\t %+d\n", -42));

	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%% di ft_printf:\t\t % d\n", 42) - 3, printf("%% di printf:\t\t % d\n", 42));
	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%% di ft_printf:\t\t % d\n", -42) - 3, printf("%% di printf:\t\t % d\n", -42));

	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", 42) - 3, printf("%%.di printf:\t\t %.d\n", 42));
	printf("ret ft_printf: %d\tret printf: %d\n\n", ft_printf("%%.di ft_printf:\t\t %.d\n", -42) - 3, printf("%%.di printf:\t\t %.d\n", -42));

	printf("ret ft_printf: %d\tret printf: %d\n", ft_printf("%%%% ft_printf:\t\t %%\n") - 3, printf("%%%% printf:\t\t %%\n"));
	return (0);
}
