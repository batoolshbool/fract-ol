/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_and_julia.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:41:45 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:16:39 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(int x, int y, t_fractol *fract)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	z.re = 0.0;
	z.im = 0.0;
	c.re = scale_map(x, fract->min_re, fract->max_re, WIDTH);
	c.im = scale_map(y, fract->max_im, fract->min_im, HEIGHT);
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

	z.re = scale_map(x, fract->min_re, fract->max_re, WIDTH);
	z.im = scale_map(y, fract->max_im, fract->min_im, HEIGHT);
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
