/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:41:51 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:18:56 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

double	scale_map(double unscaled, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled / old_max) + new_min);
}

int	is_valid_number(char *s)
{
	int	i;
	int	digit;
	int	dot;

	i = 0;
	digit = 0;
	dot = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot)
				return (0);
			dot = 1;
		}
		else if (ft_isdigit(s[i]))
			digit = 1;
		else
			return (0);
		i++;
	}
	return (digit);
}
