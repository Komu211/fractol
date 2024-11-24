/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:38:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/24 22:59:25 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
// static void	ft_hook(void *param)
//{
//	const mlx_t	*mlx = param;

//	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
//}

int32_t	main(int argc, char **argv)
{
	t_fract_data	fract_data;

	if (handle_args(argc, argv, &fract_data) != 0)
		return (EXIT_FAILURE);
	fract_data.mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	fract_data.img = mlx_new_image(fract_data.mlx, WIDTH, HEIGHT);
	if (!fract_data.img || (mlx_image_to_window(fract_data.mlx, fract_data.img,
				0, 0) < 0))
		ft_error();
	mlx_loop_hook(fract_data.mlx, &handle_keypress, &fract_data);
	mlx_loop(fract_data.mlx);
	return (EXIT_SUCCESS);
}
