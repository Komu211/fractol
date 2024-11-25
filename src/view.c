/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:36 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 01:05:13 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_fract_data *fract_data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (fract_data->type == FRACTAL_MANDELBROT)
				color = get_mandelbrot_color(x, y);
			// else if (fract_data->type == FRACTAL_JULIA)
			//	color = get_julia_color(x, y);
			// else if (fract_data->type == FRACTAL_BURNING_SHIP)
			//	color = get_burning_ship_color(x, y);
			mlx_put_pixel(fract_data->img, x, y, color);
			x++;
		}
		y++;
	}
	fract_data->img = mlx_new_image(fract_data->mlx, WIDTH, HEIGHT);
}
