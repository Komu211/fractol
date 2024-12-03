/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:22:33 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/03 17:38:15 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fract_data	*fract_data;
	mlx_t			*mlx;

	(void)xdelta;
	fract_data = (t_fract_data *)param;
	mlx = (mlx_t *)fract_data->mlx;
	if (!mlx)
		return ;
	if (ydelta > 0 && fract_data->zoom <= 30400760612153)
		fract_data->zoom *= 1.1;
	else if (ydelta < 0)
		fract_data->zoom *= 0.9;
	render_fractal(fract_data);
}
