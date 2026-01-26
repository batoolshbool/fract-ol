/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:40:57 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 17:12:22 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_init(t_fractol *fract)
{
	fract->connection = mlx_init();
	if (!fract->connection)
		exit_error("malloc error");
	fract->window = mlx_new_window(fract->connection, WIDTH, HEIGHT,
			fract->name);
	if (!fract->window)
	{
		mlx_destroy_display(fract->connection);
		free(fract->connection);
		exit_error("malloc error");
	}
	fract->img.img = mlx_new_image(fract->connection, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->connection, fract->window);
		mlx_destroy_display(fract->connection);
		free(fract->connection);
		exit_error("malloc error");
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
	//event_init(fract);
}
