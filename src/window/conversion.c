/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:59:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 22:00:17 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_plane(int x, int y, t_fract_data *fract_data)
{
	t_complex	plane_coord;
	double		aspect_ratio;
	double		scale;

	aspect_ratio = (double)WIDTH / HEIGHT;
	scale = 4.0;
	if (aspect_ratio > 1.0)
	{
		plane_coord.re = (x - WIDTH / 2.0) * scale / (WIDTH * fract_data->zoom)
			+ fract_data->x_offset;
		plane_coord.im = (y - HEIGHT / 2.0) * scale / (WIDTH * fract_data->zoom)
			+ fract_data->y_offset;
	}
	else
	{
		plane_coord.re = (x - WIDTH / 2.0) * scale / (HEIGHT * fract_data->zoom)
			+ fract_data->x_offset;
		plane_coord.im = (y - HEIGHT / 2.0) * scale / (HEIGHT
				* fract_data->zoom) + fract_data->y_offset;
	}
	return (plane_coord);
}
