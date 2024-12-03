/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:17:19 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/03 16:32:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_fract_data *fract_data, t_complex fixed)
{
	t_complex	z;
	long double		tmp;
	int			i;

	z = screen_to_plane(x, y, fract_data);
	i = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i < 100)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + fixed.re;
		z.im = 2 * tmp * z.im + fixed.im;
		i++;
	}
	return (i);
}
