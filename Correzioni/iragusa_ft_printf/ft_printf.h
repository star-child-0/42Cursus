/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:25:08 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/06 15:25:13 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdint.h>// uintptr_t 
# include	<unistd.h>// write
# include	<stdlib.h>// malloc free
# include	<stdarg.h>// va_start va_arg va_copy va_end va_list
# include	"libft/libft.h"

typedef struct s_flags
{
	int		meno;
	int		zero;
	int		punto;
	int		sign;
	int		canc;
	int		wdt;
	int		prec;
	int		sp;
	int		len;
	int		ret;
	va_list	next;
}	t_flags;

t_flags		*ft_inizializza_flag(t_flags *flag);
int			ft_printf(const char *src, ...);
const char	*ft_checkchar(t_flags *flag, const char *src);
char		*ft_strncpy(char *dest, const char *src, unsigned int n);
const char	*ft_isflag(t_flags *flag, const char *src);
const char	*ft_wdt(t_flags *flag, const char *src);
const char	*ft_prec(t_flags *flag, const char *src);
const char	*ft_convchar(t_flags *flag, const char *src);
char		*ft_struint(char *ptr, unsigned long u);
//len
size_t		ft_ptr_len(unsigned long ptr, t_flags *flag);
size_t		ft_uintlen(unsigned int u);
size_t		ft_numlen(int d);
size_t		ft_hexlen(unsigned long x);
//Prints
void		ft_put_c(int c, t_flags *flag);
void		ft_put_s(char *s, t_flags *flag);
void		ft_put_p(unsigned long p, t_flags *flag);
void		ft_intflag(int d, t_flags *flag);
void		ft_uint_flag(t_flags *flag);
void		ft_putint(int n, t_flags *flag);
void		ft_put_di(int n, t_flags *flag);
void		ft_put_u(unsigned long u, t_flags *flag);
void		ft_put_upx(unsigned int x, t_flags *flag);
void		ft_put_lowx(unsigned int x, t_flags *flag);
void		ft_print_lowhex(unsigned long x, t_flags *flag);
void		ft_print_uphex(unsigned long x, t_flags *flag);
void		ft_print_flag(t_flags *flag);
void		ft_printprec(t_flags *flag);
void		ft_print_space(t_flags *flag);
void		ft_print_zero(t_flags *flag);
void		ft_print_space2(t_flags *flag);
void		ft_putchar(char c);
void		ft_printsrc(const char *src, t_flags *flag);
void		ft_print_num(char *ptr, int n, t_flags *flag);
void		ft_putint_fd(int n, int fd, t_flags *flag);
void		ft_print_sign(int d, t_flags *flag);
void		ft_print_numzero(t_flags *flag);
void		ft_print_space_s(t_flags *flag);
#endif
