/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdt_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:55 by iragusa           #+#    #+#             */
/*   Updated: 2022/11/02 17:28:12 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(n + 1);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

const char	*ft_wdt(t_flags *flag, const char *src)
{
	char			*ptr_w;
	unsigned int	i;

	ptr_w = NULL;
	i = 0;
	while (ft_findchar(src[i], "1234567890"))
		i++;
	ptr_w = ft_strncpy(ptr_w, src, i);
	flag->wdt = ft_atoi(ptr_w);
	free(ptr_w);
	return (src + i);
}		

const char	*ft_prec(t_flags *flag, const char *src)
{
	unsigned int	i;
	char			*ptr_p;

	i = 0;
	if (*src == '.')
	{	
		flag->zero = 0;
		flag->punto = 1;
		src++;
		if (ft_findchar(*src, "1234567890"))
		{
			ptr_p = NULL;
			while (ft_findchar(src[i], "1234567890"))
				i++;
			ptr_p = ft_strncpy(ptr_p, src, i);
			flag->prec = ft_atoi(ptr_p);
			free (ptr_p);
		}
		else
			flag->prec = 0;
	}
	return (src + i);
}	

void	ft_intflag(int d, t_flags *flag)
{
	if (!flag->zero && !flag->meno && flag->wdt > flag->prec)
	{	
		if ((flag->sign || flag->sp) && d > 0)
			flag->wdt --;
		ft_print_space(flag);
	}
}

void	ft_uint_flag(t_flags *flag)
{	
	if (!flag->zero && !flag->meno && flag->wdt > flag->prec)
		ft_print_space(flag);
	if (flag->zero)
		ft_print_zero(flag);
}
