/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:03:15 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:01:17 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	burning_ship(int x, int y, t_fractol *fract)
{
	t_complex	z;
	t_complex	c;
	double		tmp;
	int			i;

	z.re = 0.0;
	z.im = 0.0;
	c.re = scale_map(x, fract->min_re, fract->max_re, 0, WIDTH);
	c.im = scale_map(y, fract->max_im, fract->min_im, 0, HEIGHT);
	i = 0;
	while (i < MAX_ITER)
	{
		z.re = fabs(z.re);
		z.im = fabs(z.im);
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		i++;
	}
	return (MAX_ITER);
}
