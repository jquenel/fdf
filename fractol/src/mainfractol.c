/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:01:14 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/04 19:59:08 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <inttypes.h>

#include <stdio.h>
int		evaluate(double real, double imag, int iter)
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
		zr = zr * zr - zi * zi + real;
		zi = 2 * zt * zi + imag;
		if (zr * zr + zi * zi >= 4)
			return ((zr * zr + zi * zi) / 4 * iter + i * 0x02020100);
	}
	return ((zr * zr + zi * zi) / 4  * iter );
}

void	draw_fractal(double ax, double bx, double ay, double by, char **img, int iter)
{
	int		i;
	int		j;
	double	px;
	double	py;
	double	real;
	double	imag;

	px = (bx - ax) / 1000;
	py = (by - ay) / 1000;
	i = -1;
	while (++i < 1000)
	{
		j = -1;
		real = ax + i * px;
		while (++j < 1000)
		{
			imag = ay + j * py;
			//if (evaluate(real, imag, iter))
				((uint32_t *)(*img))[i + j * 1000] = evaluate(real, imag, iter);
		}
	}
}

int main(int argc, const char *argv[])
{
	void	*mlx;
	void	*win;
	void	*ptr;
	char	*img;
	int		p[10];

	(void)argc;
	(void)argv;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fractol");
	ptr = mlx_new_image(mlx, 1000, 1000);
	img = mlx_get_data_addr(ptr, &(p[0]), &(p[1]), &(p[2]));
	draw_fractal(-2.0, 1.0, -2.0, 1.0, &img, 30);
	mlx_put_image_to_window(mlx, win, ptr, 0, 0);

	mlx_loop(mlx);
	return 0;
}
