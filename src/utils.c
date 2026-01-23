/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:41:51 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/23 15:49:51 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    exit_error(char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

double  scale_map(double unscaled, double new_min, double new_max, double old_min, double old_max)
{
    return ((new_max - new_min) * (unscaled - old_min) / (old_max - old_min) + new_min);
}
