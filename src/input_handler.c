/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:08:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 14:57:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_args(int argc, char **argv, t_fract_data *fract_data)
{
	if (argc != 2 && argc != 4)
	{
		ft_printf("Usage: ./fractol [mandelbrot/julia/burning_ship]\n");
		return (EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		fract_data->type = FRACTAL_MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
		{
			ft_printf("Usage for Julia set: ./fractol julia <real> <imaginary>\n");
			return (EXIT_FAILURE);
		}
		fract_data->type = FRACTAL_JULIA;
	}
	else if (ft_strcmp(argv[1], "nova") == 0)
		fract_data->type = FRACTAL_BURNING_SHIP;
	else
	{
		ft_printf("Usage: ./fractol [mandelbrot/julia/burning_ship]\n");
		return (EXIT_FAILURE);
	}
	init_fract_data(fract_data, argv);
	return (EXIT_SUCCESS);
}
