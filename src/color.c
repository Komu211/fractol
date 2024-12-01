/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:15:08 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/12/01 18:28:53 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	escape_to_color(int escape_iter, int max_iter)
{
	if (escape_iter == max_iter) // black, so full opaque, no other colors needed
		return (255);
	return (escape_iter);
}
