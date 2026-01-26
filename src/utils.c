/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:41:51 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 19:01:01 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

double	scale_map(double unscaled, double new_min, double new_max,
		double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min)
		+ new_min);
}

float	ft_atof(const char *s)
{
	float	result;
	float	div;
	int		sign;

	result = 0.0;
	div = 1.0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			div *= 10;
			result += (*s - '0') / div;
			s++;
		}
	}
	return (result * sign);
}

int	is_valid_number(char *s)
{
	int	i;
	int	has_digit;
	int	has_dot;

	i = 0;
	has_digit = 0;
	has_dot = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (has_dot)
				return (0);
			has_dot = 1;
		}
		else if (ft_isdigit(s[i]))
			has_digit = 1;
		else
			return (0);
		i++;
	}
	return (has_digit);
}

