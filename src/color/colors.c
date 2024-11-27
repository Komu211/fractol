/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 00:45:09 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 01:00:24 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

u_int32_t	get_rgba_color(u_int8_t r, u_int8_t g, u_int8_t b, u_int8_t a)
{
	return ((u_int32_t)((a << 24) | (r << 16) | (g << 8) | b));
}

// First, let's make it work without the color scheme parameter
uint32_t	escape_to_color(int escape_time, int max_iter)
{
	double	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	if (escape_time == max_iter)
		return (255);
	t = 1.0 - ((double)escape_time / max_iter);
	r = (sin(t * 4.0) + 1.0) * 127.5;
	g = (sin(t * 4.0 + 2.0 * M_PI / 3.0) + 1.0) * 127.5;
	b = (sin(t * 4.0 + 4.0 * M_PI / 3.0) + 1.0) * 127.5;
	return (get_rgba_color(r, g, b, 255));
}
