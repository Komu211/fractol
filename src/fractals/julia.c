/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:17:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 14:09:59 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_fract_data *fract_data, double fixed_re,
		double fixed_im)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fract_data->zoom)
		+ fract_data->x_offset;
	z_im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fract_data->zoom)
		+ fract_data->y_offset;
	i = 0;
	while ((z_re * z_re + z_im * z_im) < 4 && i < 100)
	{
		tmp = z_re;
		z_re = z_re * z_re - z_im * z_im + fixed_re;
		z_im = 2 * tmp * z_im + fixed_im;
		i++;
	}
	return (i);
}
