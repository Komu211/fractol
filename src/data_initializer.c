/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initializer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:10:14 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/04 17:55:32 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fract_data(t_fract_data *fract_data, char **argv)
{
	fract_data->zoom = 1.0;
	fract_data->x_offset = 0.0;
	fract_data->y_offset = 0.0;
	if (fract_data->type == FRACTAL_JULIA)
	{
		fract_data->julia.re = ft_atof(argv[2]);
		fract_data->julia.im = ft_atof(argv[3]);
	}
	fract_data->scheme = BLUE;
	fract_data->win.width = WIDTH;
	fract_data->win.height = HEIGHT;
}
