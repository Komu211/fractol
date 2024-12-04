/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:38:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/04 15:31:12 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_error(void)
{
	write(2, mlx_strerror(mlx_errno), ft_strlen(mlx_strerror(mlx_errno)));
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_fract_data	fract_data;

	if (handle_args(argc, argv, &fract_data) != 0)
		return (EXIT_FAILURE);
	fract_data.mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (!fract_data.mlx)
		ft_error();
	fract_data.img = mlx_new_image(fract_data.mlx, WIDTH, HEIGHT);
	if (!fract_data.img || (mlx_image_to_window(fract_data.mlx, fract_data.img,
				0, 0) < 0))
	{
		mlx_terminate(fract_data.mlx);
		ft_error();
	}
	mlx_loop_hook(fract_data.mlx, &handle_keypress, &fract_data);
	mlx_scroll_hook(fract_data.mlx, &handle_scroll, &fract_data);
	mlx_loop(fract_data.mlx);
	mlx_terminate(fract_data.mlx);
	return (EXIT_SUCCESS);
}
