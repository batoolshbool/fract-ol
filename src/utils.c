/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:41:51 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:00:50 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	exit_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

double	ft_atod(const char *s)
{
	double	result;
	double	div;
	int		sign;

	result = 0.0;
	div = 1.0;
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
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			div *= 10.0;
			result += (*s++ - '0') / div;
		}
	}
	return (result * sign);
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
