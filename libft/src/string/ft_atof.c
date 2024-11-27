/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:05:14 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/11/27 14:51:23 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

double	ft_atof(char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = (double)ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i++] != '.')
		return (result);
	decimal = (double)ft_atoi(&str[i]);
	decimal = decimal / pow(10, ft_strlen(str + i));
	result = result + decimal;
	if (sign == -1)
		return (-result);
	return (result);
}
