/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/29 19:20:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <unistd.h>

void		fdf_addpixel(int x, int y, int color, t_env *env)
{
	int		pos;
	t_color	c;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	c.i = color;
	pos = x * 4 + y * WIDTH * 4;
	//printf("[%+5d]   { %+3d : %+3d }\n", pos, x, y);
	if (pos >= 0 && pos <= WIDTH * HEIGHT * 4 - 4)
	{
		IMG(data)[pos] = c.c[3];
		IMG(data)[pos + 1] = c.c[2];
		IMG(data)[pos + 2] = c.c[1];
		IMG(data)[pos + 3] = c.c[0];
	}
}

t_bool			fdf_outofbounds(t_v3d v)
{
	return ((v.x < 0 || v.x >= WIDTH ||
			v.z < 0 || v.z >= HEIGHT) ? TRUE : FALSE);
}

int			fdf_draw_fdf(t_env *env)
{
	t_face		*face;
	t_mx4		viewm;

	mlx_clear_window(MLX, WIN);
	viewm = fdf_loadmatrix(env);
	fdf_move(env);
	if (CAM(mode) == 1)
		return (fdf_draw_hlr(env));
	face = env->map->face;
	//
	while (face)
	{
		fdf_bresenham(face->edge->n1->v, face->edge->n2->v, env);
		fdf_bresenham(face->edge->next->n1->v,
				face->edge->next->n2->v, env);
		fdf_bresenham(face->edge->next->next->n1->v,
				face->edge->next->next->n2->v, env);
		face = face->next;
	}
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
	ft_bzero(IMG(data), WIDTH * HEIGHT * 4);
	return (1);
}

void		read_face(t_env *env)
{
	int		i;
	t_edge	*e;
	t_face	*f;
	t_node	**l;

	f = MAP(face);
	l = MAP(nlist);
	i = 0;
	printf("MAP W : %d [][] MAP H : %d\n\n", MAP(w), MAP(h));
	while (*l)
	{
		printf("node [x : %.1lf][y : %.1lf]\n", (*l)->v.x, (*l)->v.y);
		l++;
	}
	while (f)
	{
		printf("*FACE#%3d\n", i);
		printf("|	a [x : %.1lf][y : %.1lf][z : %.1lf][addr : %p]\n",
				f->a->v.x, f->a->v.y, f->a->v.z, f->a);
		printf("|	b [x : %.1lf][y : %.1lf][z : %.1lf][bddr : %p]\n",
				f->b->v.x, f->b->v.y, f->b->v.z, f->b);
		printf("|	c [x : %.1lf][y : %.1lf][z : %.1lf][cddr : %p]\n",
				f->c->v.x, f->c->v.y, f->c->v.z, f->c);
		e = f->edge;
		while (e)
		{
			printf("|		n1 [x : %.1lf][y : %.1lf][z : %.1lf][addr : %p]\n",
				e->n1->v.x, e->n1->v.y, e->n1->v.z, e->n1);
			printf("|		n2 [x : %.1lf][y : %.1lf][z : %.1lf][addr : %p]\n\n",
				e->n2->v.x, e->n2->v.y, e->n2->v.z, e->n1);
			e = e->next;
		}
		f = f->next;
		i++;
	}
}


