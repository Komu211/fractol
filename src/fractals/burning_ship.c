/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:39:37 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/03 21:41:19 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(int x, int y, t_fract_data *fract_data)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	c = screen_to_plane(x, y, fract_data);
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i < 100)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * fabs(tmp * z.im) + c.im;
		i++;
	}
	return (i);
}
