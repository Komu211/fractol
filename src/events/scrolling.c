/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:22:33 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/24 19:15:07 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	mlx_t	*mlx;

	(void)xdelta;
	mlx = (mlx_t *)param;
	if (!mlx)
		return ;
	if (ydelta > 0)
		ft_printf("Scrolling up!\n");
	else if (ydelta < 0)
		ft_printf("Scrolling down!\n");
}
