/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 15:34:41 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int x, int y, t_fract_data *fract_data)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	c.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fract_data->zoom)
		+ fract_data->x_offset;
	c.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fract_data->zoom)
		+ fract_data->y_offset;
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i < 100)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		i++;
	}
	return (i);
}
