/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mode1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:24:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/02 14:56:29 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

#include <sys/time.h>
t_node			*node_convert(t_node *n2, t_env *env)
{
	t_node	*n1;

	ft_err(!(n1 = malloc(sizeof(t_node))), ERR_M, 0);
	if (n2)
	{
		n1->v.x = n2->v.x;
		n1->v.y = n2->v.y;
		n1->v.z = n2->v.z;
		n1->height = n2->height;
		n1->next = NULL;
		n1->prev = NULL;
		if (!(fdf_applymatrices(env)))
		{
			free(n1);
			return (NULL);
		}
		return (n1);
	}
	return (NULL);
}

float		fdf_orient2d(t_v3d a, t_v3d b, t_v3d c)
{
	return ((b.x - a.x) * (c.z - a.z) - (b.z - a.z) * (c.x - a.x));
}

int			hlr_limits(t_node *a, t_node *b, t_node *c, t_env *env)
{
	if (fdf_outofbounds(a->dv) && fdf_outofbounds(b->dv) &&
fdf_outofbounds(c->dv))
		return (1);
	if (a->dv.y > 40 + CAM(pos.y) || a->dv.y <= 0.1 ||
	b->dv.y > 40 + CAM(pos.y) || b->dv.y <= 0.1 ||
	c->dv.y > 40 + CAM(pos.y) || c->dv.y <= 0.1)
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
	struct timeval stop, start;

	gettimeofday(&start, NULL);
	face = MAP(face);
	//fdf_zsortfaces(env);
	while (face)
	{
		//if (fdf_orient2d(a->v, b->v, c->v) >= 0)
		if (!hlr_limits(face->a, face->b, face->c, env) &&
			fdf_orient2d(face->a->dv, face->b->dv, face->c->dv) >= 0)
		{
			fdf_bresenham(face->a->dv, face->b->dv, env);
			fdf_bresenham(face->c->dv, face->b->dv, env);
			fdf_bresenham(face->a->dv, face->c->dv, env);
			fdf_raster(face->a, face->b, face->c, env);
			//fdf_raster(face->b, face->a, face->c, env);
		}
		face = face->next;
	}
	gettimeofday(&stop, NULL);
	printf("filling took : %u micros\n", stop.tv_usec - start.tv_usec);
	gettimeofday(&start, NULL);
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
	gettimeofday(&stop, NULL);
	printf("drawing took : %u micros\n", stop.tv_usec - start.tv_usec);
	//for (int i = 0; i < WIDTH * HEIGHT; i++)
	//	printf("%d", MAP(zmap)[i]);
	return (0);
}
