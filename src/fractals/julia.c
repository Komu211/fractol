/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:17:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 15:43:58 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_fract_data *fract_data, t_complex fixed)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fract_data->zoom)
		+ fract_data->x_offset;
	z.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fract_data->zoom)
		+ fract_data->y_offset;
	i = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i < 100)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + fixed.re;
		z.im = 2 * tmp * z.im + fixed.re;
		i++;
	}
	return (i);
}
