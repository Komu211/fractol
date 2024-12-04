/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:18:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/04 14:54:45 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(int x, int y, t_fract_data *fract_data)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	c = screen_to_plane(x, y, fract_data);
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
