/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mode1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 18:24:20 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/30 01:22:55 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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
		fdf_applymatrices(&(n1->v), env);
		return (n1);
	}
	return (NULL);
}

float		fdf_orient2d(t_v3d a, t_v3d b, t_v3d c)
{
	return ((b.x - a.x) * (c.z - a.z) - (b.z - a.z) * (c.x - a.x));
}

int			fdf_draw_hlr(t_env *env)
{
	t_face		*face;
	t_node		*a;
	t_node		*b;
	t_node		*c;

	//printf("Hello HLR\n");
	face = MAP(face);
	bzero(MAP(zmap), WIDTH * HEIGHT * sizeof(int));
	fdf_zsortfaces(env);
	CAM(viewm) = fdf_loadmatrix(env);
	while (face)
	{
			a = node_convert(face->edge->n1, env);
			b = node_convert(face->edge->n2, env);
			c = node_convert(face->edge->next->n2, env);
		if (fdf_orient2d(a->v, b->v, c->v) >= 0)
			fdf_raster(*a, *b, *c, env);
			free(a);
			free(b);
			free(c);
		face = face->next;
	}
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
	ft_bzero(IMG(data), WIDTH * HEIGHT * 4);
	return (0);
}
