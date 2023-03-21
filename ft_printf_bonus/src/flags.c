/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:34:45 by anvannin          #+#    #+#             */
/*   Updated: 2023/03/21 19:55:22 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(t_flags *flags)
{
	flags->minus = '-';
	flags->zero = '0';
	flags->point = '.';
	flags->hash = '#';
	flags->space = ' ';
	flags->plus = '+';
	flags->ret = 0;
	return (flags);
}
