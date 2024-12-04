/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:22:33 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/04 14:59:52 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fract_data	*fract_data;
	mlx_t			*mlx;
	t_cursor_pos	cursor;
	t_complex		before;
	t_complex		after;

	(void)xdelta;
	fract_data = (t_fract_data *)param;
	mlx = (mlx_t *)fract_data->mlx;
	if (!mlx)
		return ;
	mlx_get_mouse_pos(mlx, &cursor.x, &cursor.y);
	before = screen_to_plane(cursor.x, cursor.y, fract_data);
	if (ydelta > 0 && fract_data->zoom <= 30400800000000)
		fract_data->zoom *= 1.1;
	else if (ydelta < 0)
		fract_data->zoom *= 0.9;
	after = screen_to_plane(cursor.x, cursor.y, fract_data);
	fract_data->x_offset += before.re - after.re;
	fract_data->y_offset += before.im - after.im;
	render_fractal(fract_data);
}
