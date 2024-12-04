/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:15:08 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/03 22:23:13 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	rgb_to_a(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

uint32_t	escape_to_color(int escape_iter, int max_iter,
		t_fract_data *fract_data)
{
	int		r;
	int		g;
	int		b;
	double	factor;

	if (escape_iter == max_iter)
		return (rgb_to_a(0, 0, 0));
	factor = (double)escape_iter / max_iter;
	if (fract_data->scheme == RED)
		return (rgb_to_a(255 * factor, 0, 0));
	else if (fract_data->scheme == GREEN)
		return (rgb_to_a(0, 255 * factor, 0));
	else if (fract_data->scheme == BLUE)
		return (rgb_to_a(0, 0, 255 * factor));
	else if (fract_data->scheme == PSYCHEDELIC)
	{
		r = sin(factor * 20) * 127 * factor + 127 * factor;
		g = sin(factor * 25) * 127 * factor + 127 * factor;
		b = sin(factor * 30) * 127 * factor + 127 * factor;
		return (rgb_to_a(r, g, b));
	}
	return (rgb_to_a(0, 0, 0));
}
