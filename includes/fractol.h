/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:58:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/02 16:34:28 by kmuhlbau         ###   ########.fr       */
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

typedef struct s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef enum e_fract_type
{
	FRACTAL_MANDELBROT,
	FRACTAL_JULIA,
	FRACTAL_NOVA
}					t_fract_type;

typedef enum e_scheme
{
	BLUE,
	RED,
	GREEN
}					t_scheme;

typedef struct s_fract_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fract_type	type;
	t_scheme		scheme;
	double			zoom;
	double			x_offset;
	double			y_offset;
	t_complex		julia;
}					t_fract_data;

void				handle_keypress(void *param);
void				handle_scroll(double xdelta, double ydelta, void *param);
int					handle_args(int argc, char **argv,
						t_fract_data *fract_data);
void				render_fractal(t_fract_data *fract_data);
int					mandelbrot(int x, int y, t_fract_data *fract_data);
void				init_fract_data(t_fract_data *fract_data, char **argv);
int					julia(int x, int y, t_fract_data *fract_data,
						t_complex fixed);
t_complex			screen_to_plane(int x, int y, t_fract_data *fract_data);
uint32_t			escape_to_color(int escape_iter, int max_iter,
						t_fract_data *fract_data);
// int					nova(int x, int y, t_fract_data *fract_data);

#endif