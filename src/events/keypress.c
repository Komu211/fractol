/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:20:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/04 18:26:14 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	handle_movement(t_fract_data *fract_data, mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) || mlx_is_key_down(mlx, MLX_KEY_D))
		fract_data->x_offset += 0.1 / fract_data->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_LEFT) || mlx_is_key_down(mlx,
			MLX_KEY_A))
		fract_data->x_offset -= 0.1 / fract_data->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_UP) || mlx_is_key_down(mlx,
			MLX_KEY_W))
		fract_data->y_offset -= 0.1 / fract_data->zoom;
	else if (mlx_is_key_down(mlx, MLX_KEY_DOWN) || mlx_is_key_down(mlx,
			MLX_KEY_S))
		fract_data->y_offset += 0.1 / fract_data->zoom;
}

static void	change_julia(t_fract_data *fract_data, mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_KP_9))
		fract_data->julia.re += 0.01;
	else if (mlx_is_key_down(mlx, MLX_KEY_KP_7))
		fract_data->julia.re -= 0.01;
	else if (mlx_is_key_down(mlx, MLX_KEY_KP_6))
		fract_data->julia.im += 0.01;
	else if (mlx_is_key_down(mlx, MLX_KEY_KP_4))
		fract_data->julia.im -= 0.01;
}

void	handle_keypress(void *param)
{
	t_fract_data	*fract_data;
	mlx_t			*mlx;

	fract_data = (t_fract_data *)param;
	mlx = (mlx_t *)fract_data->mlx;
	if (!mlx)
		return ;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(mlx);
		return ;
	}
	else if (mlx_is_key_down(mlx, MLX_KEY_C))
	{
		if (++fract_data->scheme % 4 == BLUE)
			fract_data->scheme = BLUE;
	}
	handle_movement(fract_data, mlx);
	if (fract_data->type == FRACTAL_JULIA)
		change_julia(fract_data, mlx);
	render_fractal(fract_data);
}
