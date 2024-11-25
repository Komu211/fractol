/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 01:28:22 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int x, int y)
{
	double	c_re;
	double	c_im;
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	c_im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im < 4 && i < 100)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * tmp * z_im + c_im;
		i++;
	}
	return (i);
}
