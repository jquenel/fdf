/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:01:14 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/06 20:55:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <inttypes.h>

#include <stdio.h>
int		evaluate(double c[2], int iter)
{
	double	zr;
	double	zi;
	double	zt;
	int		i;

	zr = 0.0;
	zi = 0.0;
	i = iter;
	while (i--)
	{
		zt = zr;
		zr = zr * zr - zi * zi + c[0];
		zi = 2 * zt * zi + c[1];
		if (zr * zr + zi * zi >= 4)
			return ((zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101);
	}
	return (0);
	//return ((zr * zr + zi * zi) / 4 * 20);
}

void	draw_fractal(int iter, t_env *env)
{
	int		i;
	int		j;
	double	px;
	double	py;
	double	c[2];

	px = (FAL(hx) - FAL(lx)) / WIDTH;
	py = (FAL(hy) - FAL(ly)) / HEIGHT;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		c[0] = FAL(lx) + i * px;
		while (++j < HEIGHT)
		{
			c[1] = FAL(ly) + j * py;
			((uint32_t *)(IMG(data)))[i + j * WIDTH] =
				evaluate(c, iter);
		}
	}
}

int fdf_draw_fractol(t_env *env)
{
	mlx_clear_window(MLX, WIN);
	draw_fractal(200, env);
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
	return 0;
}
