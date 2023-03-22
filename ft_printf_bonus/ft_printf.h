/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:14:43 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/22 19:41:15 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_flags
{
	int		ret;
}	t_flags;

// includes
int		ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_nbrlen(long int a);

// ft_printf.c
int		ft_printf(const char *str, ...);
int		printf_handler(const char *str, int i, va_list args, t_flags *flags);

// flags.c
t_flags	*init_flags(t_flags *flags);

// ft_puts.c
int		put_d_i(const char *str, int i, va_list args, t_flags *flags);
int		put_c(const char *str, int i, va_list args, t_flags *flags);

#endif
