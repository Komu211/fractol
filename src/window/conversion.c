/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:59:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/28 14:10:56 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_plane(int x, int y, t_fract_data *fract_data)
{
	t_complex	plane_coord;
	double		aspect_ratio;
	double		scale;

	int width = fract_data->mlx->width;   // Get current window width
	int height = fract_data->mlx->height; // Get current window height
	aspect_ratio = (double)width / height;
	scale = 4.0;
	if (aspect_ratio > 1.0)
	{
		plane_coord.re = (x - width / 2.0) * scale / (width * fract_data->zoom)
			+ fract_data->x_offset;
		plane_coord.im = (y - height / 2.0) * scale / (width * fract_data->zoom)
			+ fract_data->y_offset;
	}
	else
	{
		plane_coord.re = (x - width / 2.0) * scale / (height * fract_data->zoom)
			+ fract_data->x_offset;
		plane_coord.im = (y - height / 2.0) * scale / (height
				* fract_data->zoom) + fract_data->y_offset;
	}
	return (plane_coord);
}
