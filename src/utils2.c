/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:06:57 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:23:02 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	atod_helper(const char *s, int sign)
{
	double	ret;

	ret = 0.0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	return (ret * sign);
}

double	ft_atod(const char *s)
{
	double	result;
	double	div;
	int		sign;
	double	skiped;

	result = 0.0;
	div = 1.0;
	sign = 1;
	skiped = atod_helper(s, sign);
	while (*s >= '0' && *s <= '9')
		result = result * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			div *= 10.0;
			result += (*s++ - '0') / div;
		}
	}
	return (result);
}

