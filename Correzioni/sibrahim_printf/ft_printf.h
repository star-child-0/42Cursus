/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sibrahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:57:34 by sibrahim          #+#    #+#             */
/*   Updated: 2022/10/28 10:57:36 by sibrahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_percent(void);
int	ft_print_hex(unsigned int n, char format, char flag);
int	ft_print_nbr(int n, char flag);
int	ft_print_unsigned(unsigned int n);
int	ft_print_ptr(unsigned long long p);
#endif
