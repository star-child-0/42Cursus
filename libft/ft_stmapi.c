/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stmapi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:16:54 by anvannin          #+#    #+#             */
/*   Updated: 2022/10/11 19:16:56 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char            *str;

    i = 0;
    if(!s)
        return (0);
    str = malloc(ft_strlen((char *)s));
    while (s[i] != '\0')
    {
        str[i] = f(i, s[i]);
        i++;
    }
    return (str);    
}