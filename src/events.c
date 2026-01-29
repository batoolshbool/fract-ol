/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:32:49 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 16:58:20 by bshbool          ###   ########.fr       */
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

static void	move_view(int keycode, t_fractol *fract)
{
	double	re_range;
	double	im_range;
	double	step;

	re_range = fract->max_re - fract->min_re;
	im_range = fract->max_im - fract->min_im;
	step = 0.1;
	if (keycode == KEY_LEFT)
	{
		fract->min_re -= re_range * step;
		fract->max_re -= re_range * step;
	}
	else if (keycode == KEY_RIGHT)
	{
		fract->min_re += re_range * step;
		fract->max_re += re_range * step;
	}
	else if (keycode == KEY_UP)
	{
		fract->min_im += im_range * step;
		fract->max_im += im_range * step;
	}
	else if (keycode == KEY_DOWN)
	{
		fract->min_im -= im_range * step;
		fract->max_im -= im_range * step;
	}
}

static void	handle_color(int keycode, t_fractol *fract)
{
	if (keycode == C_KEY)
	{
		fract->color_shift++;
		if (fract->color_shift >= 9)
			fract->color_shift = 0;
		fract_render(fract);
	}
}

int	key_hook(int keycode, t_fractol *fract)
{
	if (keycode == ESC_KEY)
		close_hook(fract);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
	{
		move_view(keycode, fract);
		fract_render(fract);
	}
	handle_color(keycode, fract);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fract)
{
	double	zoom;
	double	mouse_re;
	double	mouse_im;

	if (button == SCROLL_UP)
		zoom = 0.9;
	else if (button == SCROLL_DOWN)
		zoom = 1.1;
	else
		return (0);
	mouse_re = scale_map(x, fract->min_re, fract->max_re, 0, WIDTH);
	mouse_im = scale_map(y, fract->max_im, fract->min_im, 0, HEIGHT);
	fract->min_re = mouse_re + (fract->min_re - mouse_re) * zoom;
	fract->max_re = mouse_re + (fract->max_re - mouse_re) * zoom;
	fract->min_im = mouse_im + (fract->min_im - mouse_im) * zoom;
	fract->max_im = mouse_im + (fract->max_im - mouse_im) * zoom;
	fract_render(fract);
	return (0);
}
