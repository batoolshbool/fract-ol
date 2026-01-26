/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:44:11 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 17:12:26 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	mandelbrot(int x, int y)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	z.re = 0.0;
	z.im = 0.0;
	c.re = scale_map(x, -2, 2, 0, WIDTH);
	c.im = scale_map(y, 2, -2, 0, HEIGHT);
	i = 0;
	while (i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		i++;
	}
	return (MAX_ITER);
}

int	julia(int x, int y, t_fractol *fract)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = scale_map(x, -2, 2, 0, WIDTH);
	z.im = scale_map(y, 2, -2, 0, HEIGHT);
	i = 0;
	while (i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + fract->julia.re;
		z.im = 2 * z.re * z.im + fract->julia.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		i++;
	}
	return (MAX_ITER);
}

void	fract_pixel(int x, int y, t_fractol *fract, int iter)
{
	int	color;

	if (iter == MAX_ITER)
		color = BLACK;
	else
		color = scale_map(iter, LAVENDER, BABYBLUE, 0, MAX_ITER);
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
			if (fract->type == 0)
				iter = mandelbrot(x, y);
			else
				iter = julia(x, y, fract);
			fract_pixel(x, y, fract, iter);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fract->connection, fract->window, fract->img.img, 0,
			0);
}
