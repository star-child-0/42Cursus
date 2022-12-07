/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabaffo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:49:48 by mabaffo           #+#    #+#             */
/*   Updated: 2022/12/07 17:02:09 by mabaffo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	ft_burning_ship(t_fractol *ptr)
{
	ptr->x = -1;
	while (++ptr->x < WIN_WIDTH)
	{
		ptr->y = 0;
		while (ptr->y < WIN_HEIGHT)
		{
			ft_init_fract(ptr);
			while (ptr->z_real * ptr->z_real + ptr->z_im * ptr->z_im < 4
				&& ptr->iteration < MAX_ITER)
			{
				ptr->temp = ptr->z_real * ptr->z_real - ptr->z_im
					* ptr->z_im + ptr->c_real;
				ptr->z_im = fabs(2 * ptr->z_im * ptr->z_real) + ptr->c_im;
				ptr->z_real = ptr->temp;
				ptr->iteration++;
			}
			ft_draw_pixels(ptr->x, ptr->y,
				ptr->iteration * ptr->color / MAX_ITER, ptr);
			ptr->y++;
		}
	}
}
/* The difference between this calculation and that for the Mandelbrot
 * set is that the real and imaginary components are set to their 
 * respective absolute values before squaring at each iteration.
 *
 * 	z = abs(z)² + c
 *
 * That's why we use "fabs()" function at calculation, 
 * as it returns the absolute value of a floating-point number.
 */
