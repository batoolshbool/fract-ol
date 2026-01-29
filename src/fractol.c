/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:29:45 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:38:14 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	error_msg(int nb)
{
	if (nb == 1)
	{
		ft_putendl_fd("Usage:", 2);
		ft_putendl_fd("./fractol Mandelbrot", 2);
		ft_putendl_fd("./fractol Julia <re> <im>", 2);
		ft_putendl_fd("./fractol Burning_Ship", 2);
	}
	else if (nb == 2)
		ft_putendl_fd("Error: Julia parameters must be numbers", 2);
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fract, int argc, char *argv)
{
	if (argc != 2 && argc != 4)
		error_msg(1);
	ft_memset(fract, 0, sizeof(t_fractol));
	fract->min_re = -2.0;
	fract->max_re = 2.0;
	fract->min_im = -2.0;
	fract->max_im = 2.0;
	fract->color_shift = 0;
	fract->name = argv;
}

void	fract_init(t_fractol *fract)
{
	fract->connection = mlx_init();
	if (!fract->connection)
		exit_error("mlx_init failed");
	fract->window = mlx_new_window(fract->connection,
			WIDTH, HEIGHT, fract->name);
	if (!fract->window)
	{
		mlx_destroy_display(fract->connection);
		free(fract->connection);
		exit_error("mlx_new_window failed");
	}
	fract->img.img = mlx_new_image(fract->connection, WIDTH, HEIGHT);
	if (!fract->img.img)
	{
		mlx_destroy_window(fract->connection, fract->window);
		mlx_destroy_display(fract->connection);
		free(fract->connection);
		exit_error("mlx_new_image failed");
	}
	fract->img.addr = mlx_get_data_addr(fract->img.img, &fract->img.bpp,
			&fract->img.line_len, &fract->img.endian);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;

	data_init(&fract, argc, argv[1]);
	if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
		fract.type = 0;
	else if (ft_strncmp(argv[1], "Julia", 6) == 0 && argc == 4)
	{
		printf("before\n\nre = %s \n im = %s", (argv[2]), (argv[3]));
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
			error_msg(2);
		fract.type = 1;
		fract.julia.re = ft_atod(argv[2]);
		fract.julia.im = ft_atod(argv[3]);
		printf("re = %f \n im = %f", ft_atod(argv[2]), ft_atod(argv[3]));
	}
	else if (ft_strncmp(argv[1], "Burning_Ship", 13) == 0)
		fract.type = 2;
	else
		error_msg(1);
	fract_init(&fract);
	fract_render(&fract);
	mlx_hook(fract.window, 17, 0, close_hook, &fract);
	mlx_key_hook(fract.window, key_hook, &fract);
	mlx_mouse_hook(fract.window, mouse_hook, &fract);
	mlx_loop(fract.connection);
	return (0);
}
