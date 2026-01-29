/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:26:22 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/29 17:23:23 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500

# define BLACK 0x000000
# define PINK 0xFFC0CB
# define LAVENDER 0xE6E6FA
# define PEACH 0xFFDAB9
# define MINT 0xAAF0D1
# define CORAL 0xFF7F50
# define LILAC 0xC8A2C8
# define SALMON 0xFA8072
# define BABYBLUE 0x89CFF0

# define ESC_KEY 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define C_KEY 99

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_fractol
{
	char		*name;
	void		*connection;
	void		*window;
	int			type;
	t_complex	julia;
	t_img		img;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			color_shift;
}				t_fractol;

void			exit_error(char *msg);
double			scale_map(double unscaled, double new_min,
					double new_max, double old_max);
double			ft_atod(const char *nptr);
int				is_valid_number(char *s);

int				mandelbrot(int x, int y, t_fractol *fract);
int				julia(int x, int y, t_fractol *fract);
int				burning_ship(int x, int y, t_fractol *fract);
void			fract_render(t_fractol *fract);
void			fract_init(t_fractol *fract);

int				close_hook(t_fractol *fract);
int				key_hook(int keycode, t_fractol *fract);
int				mouse_hook(int button, int x, int y, t_fractol *fract);

#endif