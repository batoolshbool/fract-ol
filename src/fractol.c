/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 20:29:45 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/21 20:34:07 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	t_fractol	fract;

	if (argc != 2 && argc != 4)
		ft_putstr_fd("Usage:\n./fractol mandelbrot\n./fractol julia <re> <im>\n",2);
	return 0;
	
}