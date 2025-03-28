/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:59:58 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/05 12:00:15 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	screen_to_plane(int x, int y, t_fract_data *fract_data)
{
	t_complex		plane_coord;
	double			aspect_ratio;
	double			scale;
	t_dimensions	win;

	win.width = fract_data->mlx->width;
	win.height = fract_data->mlx->height;
	mlx_resize_image(fract_data->img, win.width, win.height);
	aspect_ratio = (double)win.width / win.height;
	scale = 4.0;
	if (aspect_ratio > 1.0)
	{
		plane_coord.re = (x - win.width / 2.0) * scale / (win.width
				* fract_data->zoom) + fract_data->x_offset;
		plane_coord.im = (y - win.height / 2.0) * scale / (win.width
				* fract_data->zoom) + fract_data->y_offset;
	}
	else
	{
		plane_coord.re = (x - win.width / 2.0) * scale / (win.height
				* fract_data->zoom) + fract_data->x_offset;
		plane_coord.im = (y - win.height / 2.0) * scale / (win.height
				* fract_data->zoom) + fract_data->y_offset;
	}
	return (plane_coord);
}
