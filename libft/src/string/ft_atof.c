/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:05:14 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/25 15:21:33 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	i = 0;
	result = (double)ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i++] != '.')
		return (result);
	decimal = (double)ft_atoi(str[i]);
	decimal = decimal / (10 * ft_strlen(str[i]));
	result = result + decimal;
	if (sign == -1)
		return (-result);
	return (result);
}
