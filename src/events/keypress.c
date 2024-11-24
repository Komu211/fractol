/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:20:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/24 15:48:01 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_keypress(void *param)
{
	mlx_t *mlx = (mlx_t *)param;

	if (!mlx)
		return ;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	else if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx,
			MLX_KEY_D))
		ft_printf("Pressed right arrow key or 'D'\n");
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx,
			MLX_KEY_A))
		ft_printf("Pressed left arrow key or 'A'\n");
	else if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx,
			MLX_KEY_W))
		ft_printf("Pressed up arrow key or 'W'\n");
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx,
			MLX_KEY_S))
		ft_printf("Pressed down arrow key or 'S'\n");
}