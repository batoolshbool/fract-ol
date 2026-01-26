/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:29:45 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 17:21:57 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2 && argc != 4)
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (EXIT_FAILURE);
	}
	fract.name = argv[1];
	if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		fract.type = 0;
	else if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		fract.type = 1;
		fract.julia.re = ft_atof(argv[2]);
		fract.julia.im = ft_atof(argv[3]);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		return (EXIT_FAILURE);
	}
	fract_init(&fract);
	fract_render(&fract);
	//mlx_hook(fract.window, 17, 0, close_hook, &fract);
	//mlx_key_hook(fract.window, key_hook, &fract);
	//mlx_mouse_hook(fract.window, mouse_hook, &fract);
	mlx_loop(fract.connection);
	return (0);
}
