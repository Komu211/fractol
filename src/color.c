/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:15:08 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/02 16:34:03 by kmuhlbau         ###   ########.fr       */
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
	if (escape_iter == max_iter)
		return (rgb_to_a(0, 0, 0));
	if (fract_data->scheme == RED)
		return (rgb_to_a(255 * escape_iter / max_iter, 0, 0));
	else if (fract_data->scheme == GREEN)
		return (rgb_to_a(0, 255 * escape_iter / max_iter, 0));
	else if (fract_data->scheme == BLUE)
		return (rgb_to_a(0, 0, 255 * escape_iter / max_iter));
	return (rgb_to_a(0, 0, 0));
}
