/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:09 by anvannin          #+#    #+#             */
/*   Updated: 2023/01/10 19:33:56 by anvannin         ###   ########.fr       */
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

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	n;
	int			i = 8;
	while (i--)
	{
		// print_bits(n);
		// write(1, "\n", 1);
		n = n * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (n);	
}

int main(void){
	print_bits(reverse_bits(2));
}
