/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:14:43 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/31 15:18:09 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_nbrlen(long int a);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr(int nb);
int		ft_putunsign_nbr(unsigned int nb);
int		ft_putnbr_hex(unsigned long int nb, char x);
int		ft_put_pointer(uintptr_t ptr);
int		ft_printf(const char *str, ...);
char	*ft_strev(char *str);

#endif
