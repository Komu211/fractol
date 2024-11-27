/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:36 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 15:47:03 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fract_data *fract_data)
{
	int	x;
	int	y;
	int	escape_time;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fract_data->type == FRACTAL_MANDELBROT)
				escape_time = mandelbrot(x, y, fract_data);
			else if (fract_data->type == FRACTAL_JULIA)
				escape_time = julia(x, y, fract_data, fract_data->julia);
			// else if (fract_data->type == FRACTAL_NOVA)
			// 	escape_time = nova(x, y, fract_data);
			mlx_put_pixel(fract_data->img, x, y, escape_time);
			x++;
		}
		y++;
	}
}
