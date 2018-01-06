/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mode1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:24:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/03 18:15:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

#define FEDGE	face->edge
#include <sys/time.h>

float		fdf_orient2d(t_v3d a, t_v3d b, t_v3d c)
{
	return ((b.x - a.x) * (c.z - a.z) - (b.z - a.z) * (c.x - a.x));
}

int			hlr_limits(t_node *a, t_node *b, t_node *c, t_env *env)
{
	if (fdf_outofbounds(a->dv) && fdf_outofbounds(b->dv) &&
fdf_outofbounds(c->dv))
		return (1);
	if (a->dv.y > CAM_START_Y + CAM(pos.y) || a->dv.y <= 0.1 ||
	b->dv.y > CAM_START_Y + CAM(pos.y) || b->dv.y <= 0.1 ||
	c->dv.y > CAM_START_Y + CAM(pos.y) || c->dv.y <= 0.1)
		return (1);
	return (0);
}

int			fdf_determine(t_v3d a, t_v3d b, t_v3d c)
{
	return ((a.x * b.z) - (a.z * b.x) + (b.x * c.z) - (b.z * c.x)
			+ (c.x * a.z) - (c.z * a.x));
}

int			fdf_draw_hlr(t_env *env)
{
	t_face		*face;
//	struct timeval stop, start;

//	gettimeofday(&start, NULL);
	face = MAP(face);
	//fdf_zsortfaces(env);
	while (face)
	{
		//if (fdf_orient2d(a->v, b->v, c->v) >= 0)
		if (!hlr_limits(face->a, face->b, face->c, env) &&
			fdf_orient2d(face->a->dv, face->b->dv, face->c->dv) >= 0)
		{
			if (!face->edge[0]->drawn)
				face->edge[0]->drawn = fdf_bresenham(face->a->dv, face->b->dv, env);
			if (!face->edge[1]->drawn)
				face->edge[1]->drawn = fdf_bresenham(face->c->dv, face->b->dv, env);
			if (!face->edge[2]->drawn)
				face->edge[2]->drawn = fdf_bresenham(face->a->dv, face->c->dv, env);
			fdf_raster(face->a, face->b, face->c, env);
			//fdf_raster(face->b, face->a, face->c, env);
		}
		face = face->next;
	}
//	gettimeofday(&stop, NULL);
//	printf("filling took : %u micros\n", stop.tv_usec - start.tv_usec);
//	gettimeofday(&start, NULL);
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
//	gettimeofday(&stop, NULL);
//	printf("drawing took : %u micros\n", stop.tv_usec - start.tv_usec);
	//for (int i = 0; i < WIDTH * HEIGHT; i++)
	//	printf("%d", MAP(zmap)[i]);
	return (0);
}
