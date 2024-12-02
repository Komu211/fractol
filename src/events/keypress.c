/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:20:34 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/02 16:32:35 by kmuhlbau         ###   ########.fr       */
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
		ft_printf("Color scheme: %d", fract_data->scheme);
		if (++fract_data->scheme % 3 == BLUE)
			fract_data->scheme = BLUE;
	}
	handle_movement(fract_data, mlx);
	render_fractal((t_fract_data *)param);
}
