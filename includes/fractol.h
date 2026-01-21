/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:26:22 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/21 18:37:32 by bshbool          ###   ########.fr       */
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

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

/*
	*img       MLX image object
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
	
}	t_fractol;



#endif