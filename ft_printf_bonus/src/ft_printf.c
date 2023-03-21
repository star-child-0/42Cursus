/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:34:01 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/21 21:12:53 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_handler(const char *str, int i, va_list args, t_flags *flags)
{
	int	n;

	if ((str[i] == '+' || str[i] == ' ' || str[i] == '.') && (str[i + 1] == 'd'
			|| str[i + 1] == 'i'))
		i = put_d_i(str, i, args, flags);
	else if (str[i] == 'd' || str[i] == 'i')
		flags->ret += ft_putnbr(va_arg(args, int));
	else if (str[i] == '%')
		flags->ret += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	t_flags	*flags;
	va_list	args;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	flags = init_flags(flags);
	i = -1;
	va_start(args, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
			i = printf_handler(str, ++i, args, flags);
		else
			flags->ret += ft_putchar(str[i]);
	}
	va_end(args);
	ret = flags->ret;
	free(flags);
	return (ret);
}

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
