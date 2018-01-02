/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/02 14:57:23 by jquenel          ###   ########.fr       */
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
	if (MAP(zmap)[x + y * WIDTH])
		return ;
	//printf("%d\n", MAP(zmap)[x + y * WIDTH]);
	c.i = color;
	pos = x + y * WIDTH;
	if (pos >= 0 && pos < WIDTH * HEIGHT)
	{
		((int *)IMG(data))[pos] = c.i;
		MAP(zmap)[pos] = 1;
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

	mlx_clear_window(MLX, WIN);
	fdf_applymatrices(env);
	fdf_move(env);
	ft_bzero(IMG(data), WIDTH * HEIGHT * 4);
	if (CAM(mode) == 1)
		return (fdf_draw_hlr(env));
	face = env->map->face;
	while (face)
	{
		if (!face->edge[0]->drawn)
			face->edge[0]->drawn = fdf_bresenham(face->edge[0]->n1->dv,
					face->edge[0]->n2->dv, env);
		if (!face->edge[1]->drawn)
			face->edge[1]->drawn = fdf_bresenham(face->edge[1]->n1->dv,
					face->edge[1]->n2->dv, env);
		if (!face->edge[2]->drawn)
			face->edge[2]->drawn = fdf_bresenham(face->edge[2]->n1->dv,
					face->edge[2]->n2->dv, env);
		face = face->next;
	}
	fdf_clearzmapedges(env);
	mlx_put_image_to_window(MLX, WIN, IMG(ptr), 0, 0);
	return (1);
}
/*
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
		e = f->edge[0];
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
}*/
