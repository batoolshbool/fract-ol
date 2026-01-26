/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:32:49 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 19:44:45 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_hook(t_fractol *fract)
{
	mlx_destroy_image(fract->connection, fract->img.img);
	mlx_destroy_window(fract->connection, fract->window);
	mlx_destroy_display(fract->connection);
	free(fract->connection);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractol *fract)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(fract->connection, fract->img.img);
		mlx_destroy_window(fract->connection, fract->window);
		mlx_destroy_display(fract->connection);
		free(fract->connection);
		exit(0);
	}
	return (0);
}
