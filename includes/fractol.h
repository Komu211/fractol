/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:58:49 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/24 15:50:03 by kmuhlbau         ###   ########.fr       */
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

void	render_mandelbrot(void);
void	render_julia(void);
void	handle_keypress(void *param);
void	handle_scroll(double xdelta, double ydelta, void *param);

#endif