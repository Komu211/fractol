/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:48:51 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 17:49:17 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Convert escape time to RGB color
int	escape_to_rgb(int escape_time)
{
	double t = (double)escape_time / 100.0;
	int r, g, b;
	if (escape_time == 100)
		return (0x000000FF);
	t = t * 6.0; 
	if (t < 1.0)
	{
		r = 255;
		g = (int)(t * 255);
		b = 0;
	}
	else if (t < 2.0)
	{
		r = (int)((2.0 - t) * 255);
		g = 255;
		b = 0;
	}
	else if (t < 3.0)
	{
		r = 0;
		g = 255;
		b = (int)((t - 2.0) * 255);
	}
	else if (t < 4.0)
	{
		r = 0;
		g = (int)((4.0 - t) * 255);
		b = 255;
	}
	else if (t < 5.0)
	{
		r = (int)((t - 4.0) * 255);
		g = 0;
		b = 255;
	}
	else
	{
		r = 255;
		g = 0;
		b = (int)((6.0 - t) * 255);
	}
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
