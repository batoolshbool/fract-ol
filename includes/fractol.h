/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:26:22 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/26 19:38:39 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
# define ERROR_MESSAGE "Usage:\n./fractol Mandelbrot\n./fractol Julia <re> <im>\n"

// Basic colors
# define BLACK 0x000000
# define PINK 0xFFC0CB
# define LAVENDER 0xE6E6FA
# define PEACH 0xFFDAB9
# define MINT 0xAAF0D1
# define CORAL 0xFF7F50
# define LILAC 0xC8A2C8
# define SALMON 0xFA8072
# define BABYBLUE 0x89CFF0

# define ESC 65307

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
}				t_fractol;

void			exit_error(char *msg);
double			scale_map(double unscaled, double new_min, double new_max, double old_min, double old_max);
float			ft_atof(const char *nptr);
int				is_valid_number(char *s);


int				mandelbrot(int x, int y);
int				julia(int x, int y, t_fractol *fract);
void			fract_pixel(int x, int y, t_fractol *fract, int iter);
void			fract_init(t_fractol *fract);
void			fract_render(t_fractol *fract);

int			close_hook(int keycode, t_fractol *fract);
#endif