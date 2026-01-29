/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:44:11 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 18:41:08 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static int	get_iter(t_fractol *fract, int x, int y)
{
	if (fract->type == 0)
		return (mandelbrot(x, y, fract));
	if (fract->type == 1)
		return (julia(x, y, fract));
	return (burning_ship(x, y, fract));
}

void	fract_pixel(int x, int y, t_fractol *fract, int iter)
{
	int	color;

	if (iter == MAX_ITER)
		color = BLACK;
	else
		color = scale_map(iter, LAVENDER, BABYBLUE, MAX_ITER);
	ft_pixel_put(x, y, &fract->img, color);
}

void	fract_render(t_fractol *fract)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = get_iter(fract, x, y);
			fract_pixel(x, y, fract, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->connection, fract->window,
		fract->img.img, 0, 0);
}
