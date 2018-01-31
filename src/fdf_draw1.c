/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 23:30:27 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <sys/time.h>

#define IJK		i + j * FAL_SIZE + k * FAL_SIZE * FAL_SIZE

static void		init_node(t_node *n, int i, int j, int k)
{
	n->v.x = i;
	n->v.y = j;
	n->v.z = k;
	n->lit = 0;
	n->active = 0;
	n->fvalue = 0;
	i = MAX_NFACE;
	while (i--)
		n->face[i] = NULL;
	n->next = NULL;
	n->prev = NULL;
}

static void	init_cloud(t_env *env)
{
	int		i;
	int		j;
	int		k;
	t_node	*n;

	//ft_err(!(FAL(nlist) = (t_node ****)malloc(sizeof(t_node ***) * FAL_SIZE)),
	//		ERR_M, 0);
	i = FAL_SIZE;
	while (i--)
	{
	//	ft_err(!(FAL(nlist)[i] =
	//		(t_node ***)malloc(sizeof(t_node **) * FAL_SIZE)), ERR_M, 0);
		j = FAL_SIZE;
		while (j--)
		{
	//		ft_err(!(FAL(nlist)[i][j] =
	//		(t_node **)malloc(sizeof(t_node *) * FAL_SIZE)), ERR_M, 0);
			k = FAL_SIZE;
			while (k--)
			{
				ft_err(!(n = fdf_newnode(ft_v3d_new(i, j, k))), ERR_M, 0);
				fdf_addnode(&MAP(node), n);
				FAL(nlist)[IJK] = n;
			}
		}
	}
}

t_bool		evaluate3d(t_node *point, double c[2], int iter)
{
	return (TRUE);
}

/*
t_bool		evaluate3d(t_node *point, double c[2], int iter)
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
			point->fvalue = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
			return ((point->lit = FALSE));
		}
	}
	point->fvalue = (zr * zr + zi * zi) / 4 * iter + i / 2 * 0x00020101;
	return ((point->lit = TRUE));
}
*/
void		build_a_test(t_env *env)
{
	FAL(nlist)[0]->lit = 0;
	FAL(nlist)[1]->lit = 1;
	FAL(nlist)[2]->lit = 1;
	FAL(nlist)[3]->lit = 1;
	FAL(nlist)[4]->lit = 0;
	FAL(nlist)[5]->lit = 0;
	FAL(nlist)[6]->lit = 0;
	FAL(nlist)[7]->lit = 0;
}

void		fdfractol(t_env *env)
{
	int			i[3];
	double		nv[2];
	double		c[2];

	init_cloud(env);
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
				evaluate3d(FAL(nlist)[i[0] + 
						(i[1] + i[2] * FAL_SIZE) * FAL_SIZE], c, FAL_ITER);
			}
		}
	}
	build_a_test(env);
	printf("computed all points\n");
	printf("hello\n");
	fdf_clean_cloud(env);
	printf("cleaned cloud\n");
	fdf_create_folume(env);
	printf("created folume !!!\n");
	//read_face(env);
}
