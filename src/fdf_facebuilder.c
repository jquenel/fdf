/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_facebuilder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:59:52 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/29 14:14:02 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**		NA-----NB
**		|      |
**		|      |
**		|      |
**		ND-----NC
*/

#define NA		(MAP(nlist)[i])
#define NB		(MAP(nlist)[i + 1])
#define	NC		(MAP(nlist)[i + MAP(h) + 1])
#define ND		(MAP(nlist)[i + MAP(h)])

static int			facedecider(float a, float b, float c, float d)
{
	if (a > c)
	{
		if (b > d)
			return (a - c > b - d ? 1 : 0);
		else
			return (a - c > d - b ? 1 : 0);	
	}
	else
	{
		if (b > d)
			return (c - a > b - d ? 1 : 0);
		else
			return (c - a > d - b ? 1 : 0);
	}
}

static void			facehelper(int i, t_env * env)
{
	if ((i + 1) % MAP(h))
	{
		if (facedecider(-NA->v.z, -NB->v.z, -NC->v.z, -ND->v.z))
		{
			fdf_addface(&MAP(face), fdf_newface(NA, NB, ND));
			fdf_addface(&MAP(face), fdf_newface(NB, NC, ND));
		}
		else
		{
			fdf_addface(&MAP(face), fdf_newface(NA, NB, NC));
			fdf_addface(&MAP(face), fdf_newface(NA, NC, ND));
		}
	}
}

void				fdf_facebuilder(t_env *env)
{
	t_node	*tmp;
	int		i;
	int		node_count;

	tmp = env->map->node;
	fdf_get_nlist(env);
	while (tmp)
	{
		tmp->v.x -= env->map->w / 2;
		tmp->v.y -= env->map->h / 2;
		tmp->v.z /= CAM(yratio) / -4;
		//zoom adjustment to fix//
		tmp = tmp->next;
	}
	fdf_savepoint(env);
	i = 0;
	node_count = fdf_nodecount(env);
	ft_printf("building faces");
	while (NA && NB && ND && NC && i + MAP(h) < node_count)
	{
		facehelper(i, env);
		ft_printf(i++ % 100 ? "." : "");
	}
	//read_face(env);
	ft_printf("\nOK\n");
}
