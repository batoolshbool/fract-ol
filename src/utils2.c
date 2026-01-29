/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:06:57 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 18:24:47 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	atod_helper(const char *s)
{
	double	div;
	double	result;

	div = 1.0;
	result = 0.0;
	while (*s >= '0' && *s <= '9')
	{
		div *= 10.0;
		result += (*s - '0') / div;
		s++;
	}
	return (result);
}

double	ft_atod(const char *s)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10.0 + (*s++ - '0');
	if (*s == '.')
		result += atod_helper(++s);
	return (result * sign);
}
