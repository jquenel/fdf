/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/06 23:50:21 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <sys/time.h>

void		evaluate3d(t_node *n, double c[2], int iter)
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
		{
			n->fvalue = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
			n->lit = FALSE;
			return ;
		}
	}
	n->fvalue = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
	n->lit = TRUE;
	//return ((zr * zr + zi * zi) / 4 * 20);
}
/*
void	draw_fractal3d(int iter, t_env *env)
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
*/

void		fdfractol(t_env *env, char *arg)
{
	int			i[3];
	double		nv[2];
	double		c[2];
	t_node		*node;
	t_tinfos	tinfos;
	struct timeval stop, start;

	(void)arg;
	gettimeofday(&start, NULL);
	nv[0] = (FAL(hx) - FAL(lx)) / FAL_SIZE;
	nv[1] = (FAL(hy) - FAL(ly)) / FAL_SIZE;
	i[0] = -1;
	while (++(i[0]) < FAL_SIZE)
	{
		i[1] = -1;
		printf("[%d, %d, %d]\n", i[0], i[1], i[2]);
		while (++(i[1]) < FAL_SIZE)
		{
			c[0] = FAL(lx) + sqrt(i[1] * i[1] + i[0] * i[0]) * nv[0];
			i[2] = -1;
			while (++(i[2]) < FAL_SIZE)
			{
				c[1] = FAL(ly) + i[2] * nv[1];
				ft_err(!(node = fdf_newnode(ft_v3d_new(i[0], i[1], i[2]))), ERR_M, 0);
				evaluate3d(node, c, FAL_ITER);
				fdf_addnode(&(MAP(node)), node);
				fdf_addface(&MAP(face), fdf_newface(node, NULL, NULL, env));
			}
		}
	}
	gettimeofday(&stop, NULL);
	printf("time took : %lu\n", stop.tv_sec - start.tv_sec);
}
