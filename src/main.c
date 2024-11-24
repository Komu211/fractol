/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:38:13 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/24 15:49:28 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIDTH 1920
#define HEIGHT 1080

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

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0x00FF00FF);
	// Pass mlx directly to the loop hook
	mlx_loop_hook(mlx, &handle_keypress, mlx);
	mlx_scroll_hook(mlx, &handle_scroll, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
