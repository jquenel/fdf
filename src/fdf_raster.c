/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_raster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:11:12 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 20:36:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <unistd.h>
#define DET_AB		face->edge->det
#define DET_BC		face->edge->next->det
#define DET_CA		face->edge->next->next->det

static float	min3f(float a, float b, float c)
{
	if (a > b)
		return (b > c ? lround(c) : lround(b));
	return (a > c ? lround(c) : lround(a));
}

static float	max3f(float a, float b, float c)
{
	if (a < b)
		return (b < c ? lround(c) : lround(b));
	return (a < c ? lround(c) : lround(a));
}

int				fdf_get_color(t_node *a, t_node *b, t_node *c, t_v3d *v,
								t_env *env)
{
	t_color		col;

	if (CAM(cmode) == 1)
	{
		col.c[0] = MIN(255, (a->v.z * ft_v3d_mag(ft_v3d_sub(a->dv, *v))));
		col.c[1] = MIN(255, (b->v.z * ft_v3d_mag(ft_v3d_sub(b->dv, *v))));
		col.c[2] = MIN(255, (c->v.z * ft_v3d_mag(ft_v3d_sub(c->dv, *v))));
		col.c[3] = MIN(255, (v->y) * 2.5);
	}
	if (CAM(cmode) == 2)
	{
		col.c[0] = fdf_orient2d(a->dv, b->dv, *v) / 2;
		col.c[1] = fdf_orient2d(b->dv, c->dv, *v) / 2;
		col.c[2] = fdf_orient2d(c->dv, a->dv, *v) / 2;
		//col.c[3] = MIN(255, (v->y) * 2.5);
	}
	return (col.i);
}

int			raster_draw(t_node *a, t_node *b, t_node *c, int i[3], t_env *env)
{
	int	det[3];
	t_v3d	v;

	v = ft_v3d_new(i[0], (a->dv.y + b->dv.y + c->dv.y) / 3, i[2]);
	det[0] = fdf_orient2d(a->dv, b->dv, v);
	det[1] = fdf_orient2d(b->dv, c->dv, v);
	det[2] = fdf_orient2d(c->dv, a->dv, v);
	if (det[0] >= 0 && det[1] >= 0 && det[2] >= 0)
	{
		fdf_addpixel(i[0], i[2],// C_WHITE, env);
		CAM(cmode) ? fdf_get_color(a, b, c, &v, env) : C_WHITE, env);
		//MAP(zmap)[i[0] + i[2] * WIDTH] = 1;
	}
	return (1);
}

void		fdf_raster(t_node *a, t_node *b, t_node *c, t_env *env)
{
	int			i[3];
	int			bound[2];

	//printf("Hello raster\na [%.1lf : %.1lf : %.1lf]\nb [%.1lf : %.1lf : %.1lf]\nc [%.1lf : %.1lf : %.1lf]\n", a->dv.x, a->dv.y, a->dv.z, b->dv.x, b->dv.y, b->dv.z, c->dv.x, c->dv.y, c->dv.z);
	i[0] = MAX(0, (int)(min3f(a->dv.x, b->dv.x, c->dv.x))) - 1;
	bound[0] = MIN(WIDTH, (int)(max3f(a->dv.x, b->dv.x, c->dv.x)));
	i[1] = MAX(0, (int)(min3f(a->dv.z, b->dv.z, c->dv.z)));
	bound[1] = MIN(HEIGHT, (int)(max3f(a->dv.z, b->dv.z, c->dv.z)));
	while (++(i[0]) <= bound[0])
	{
		i[2] = i[1] - 1;
		while (++(i[2]) <= bound[1])
		{
			//if (!(MAP(zmap)[i[0] + i[2] * WIDTH]))
				raster_draw(a, b, c, i, env);
		}
	}
	sleep(0);
}
