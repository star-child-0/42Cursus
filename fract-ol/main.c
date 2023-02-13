/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:57:12 by anvannin          #+#    #+#             */
/*   Updated: 2023/02/13 18:12:57 by anvannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	if (!ft_strncmp(argv[1], "Julia", ft_strlen("Julia")))
		ft_printf("Julia\n");
	else if (!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Julia")))
		ft_printf("Mandelbrot\n");
	return (0);	
}
