/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:14:43 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/25 18:53:44 by anvannin         ###   ########.fr       */
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
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		ret;
}	t_flags;

// includes
int		ft_putchar(char c);
int		ft_atoi(const char *str);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_nbrlen(long int a);
int		ft_put_pointer(uintptr_t ptr);
int		ft_putnbr_hex(unsigned long int nb, char x);
int		ft_putunsign_nbr(unsigned int nb);

// ft_printf.c
int		ft_printf(const char *str, ...);
t_flags	*init_flags(t_flags *flags);
int		flags_handler(const char *str, int i, va_list args, t_flags *flags);
int		printf_handler(const char *str, int i, va_list args, t_flags *flags);

// flags_handlers
int		minus_handler(const char *str, int i, va_list args, t_flags *flags);
int		zero_handler(const char *str, int i, va_list args, t_flags *flags);
int		dot_handler(const char *str, int i, va_list args, t_flags *flags);

int		hash_handler(const char *str, int i, va_list args, t_flags *flags);
int		space_handler(const char *str, int i, va_list args, t_flags *flags);
int		plus_handler(int i, va_list args, t_flags *flags);

// ft_puts.c
int		put_d_i(const char *str, int i, va_list args, t_flags *flags);
int		put_c(const char *str, int i, va_list args, t_flags *flags);

#endif
