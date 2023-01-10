/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:54:29 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:15 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	n;
	int			i = 8;
	while (i--)
	{
		n = (octet >> i & 1) + '0';
		write(1, &n, 1);
	}
}

int main(void){
	print_bits(2);
}