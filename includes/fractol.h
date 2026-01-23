/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:26:22 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/23 15:54:42 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <sys/time.h>
#include "libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 500
# define ERROR_MESSAGE "Usage:\n./fractol Mandelbrot\n./fractol Julia <re> <im>\n"

// Basic colors
# define BLACK   0x000000
# define PINK    0xFFC0CB
# define LAVENDER 0xE6E6FA
# define PEACH   0xFFDAB9
# define MINT    0xAAF0D1
# define CORAL   0xFF7F50
# define LILAC   0xC8A2C8
# define SALMON  0xFA8072
# define BABYBLUE 0x89CFF0


typedef struct s_complex
{
double re;
double im;
} t_complex;

typedef struct s_img
{
void *img;
char *addr;
int bpp;
int line_len;
int endian;
} t_img;

/*
*img       MLX image object/struct
*addr      pointer to pixels
*bpp       bits per pixel (usually 32)
*line_len  bytes per row
*endian    byte order
*addr
*
*[ R G B A ][ R G B A ][ R G B A ] ...
*/

typedef struct s_fractol
{
    char    *name;
    void    *connection;
    void    *window;
    int     type;
t_img   img;

} t_fractol;

/*
    *connection     mlx_init();
    *window         mlx_new_window();
*/

void    exit_error(char *msg);
double  scale_map(double unscaled, double new_min, double new_max, double old_min, double old_max);

void    data_init(t_fractol *fract);
void    fract_init(t_fractol    *fract);
void    fract_pixel(int x, int y, t_fractol *fract);
void    fract_render(t_fractol *fract);

#endif