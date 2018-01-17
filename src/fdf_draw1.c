/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/11 21:45:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <sys/time.h>


t_bool		evaluate3d(t_finfos *point, double c[2], int iter)
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
			point->value = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
			return ((point->lit = FALSE));
		}
	}
	point->value = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
	return ((point->lit = TRUE));
}

void		fdfractol(t_env *env)
{
	int			i[3];
	double		nv[2];
	double		c[2];
	t_finfos	cloud[FAL_SIZE * FAL_SIZE * FAL_SIZE];

	nv[0] = (FAL(hx) - FAL(lx)) / FAL_SIZE;
	nv[1] = (FAL(hy) - FAL(ly)) / FAL_SIZE;
	i[0] = -1;
	while (++(i[0]) < FAL_SIZE)
	{
		i[1] = -1;
		c[0] = FAL(lx) + i[0] * nv[0];
		printf("[%d, %d, %d]\n", i[0], i[1], i[2]);
		while (++(i[1]) < FAL_SIZE)
		{
			i[2] = -1;
			while (++(i[2]) < FAL_SIZE)
			{
				c[1] = FAL(ly) + sqrt(i[2] * i[2] + i[1] * i[1]) * nv[1];
				evaluate3d(&(cloud[i[0] + (i[1] + i[2] * FAL_SIZE) *
							FAL_SIZE]), c, FAL_ITER);
			}
		}
	}
	fdf_fildefractol(cloud, env);
}
