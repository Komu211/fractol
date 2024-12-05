/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:08:17 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/05 12:34:37 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_usage(void)
{
	ft_printf("Usage: ./fractol [mandelbrot/julia/burning_ship]\n");
	ft_printf("Usage for Julia: ./fractol julia <real> <imaginary>\n");
	ft_printf("Controls:\n");
	ft_printf("Move: Arrow keys or W, A, S, D\n");
	ft_printf("Zoom: Mouse wheel\n");
	ft_printf("Change color scheme: C\n");
	ft_printf("Change Julia appearence:\n");
	ft_printf("\tReal:\t\tNumPad 9, NumPad 7\n");
	ft_printf("\tImaginary:\tNumPad 6, NumPad 4\n");
}

int	handle_args(int argc, char **argv, t_fract_data *fract_data)
{
	if (argc != 2 && argc != 4)
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	if ((ft_strcmp(argv[1], "mandelbrot") == 0) && argc == 2)
		fract_data->type = FRACTAL_MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		if (argc != 4)
		{
			ft_printf("Usage for Julia: ./fractol julia <real> <imaginary>\n");
			return (EXIT_FAILURE);
		}
		fract_data->type = FRACTAL_JULIA;
	}
	else if ((ft_strcmp(argv[1], "burning_ship") == 0) && argc == 2)
		fract_data->type = FRACTAL_BURNING_SHIP;
	else
	{
		print_usage();
		return (EXIT_FAILURE);
	}
	init_fract_data(fract_data, argv);
	return (EXIT_SUCCESS);
}
