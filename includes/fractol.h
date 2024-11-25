/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:58:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 01:03:15 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <MLX42.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef enum e_fract_type
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA,
	FRACTAL_BURNING_SHIP
}					t_fract_type;

typedef struct s_fract_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fract_type	type;
}					t_fract_data;

void				render_mandelbrot(t_fract_data *fract_data);
void				render_julia(void);
void				handle_keypress(void *param);
void				handle_scroll(double xdelta, double ydelta, void *param);
int					handle_args(int argc, char **argv,
						t_fract_data *fract_data);
void				render_fractal(t_fract_data *fract_data);
int					get_mandelbrot_color(int x, int y);

#endif