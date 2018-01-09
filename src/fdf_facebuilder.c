/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_facebuilder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:59:52 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/09 17:19:09 by jquenel          ###   ########.fr       */
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

static void			fdf_specialfaces(t_env *env)
{
	t_node	*node;

	if (MAP(h) == 1 || MAP(w) == 1)
	{
		if (MAP(w) == 1 && MAP(h) == 1)
			fdf_addface(&MAP(face), fdf_newface(MAP(node), NULL, NULL, env));
		else
		{
			node = MAP(node);
			while (node && node->next)
			{
				fdf_addface(&MAP(face),
						fdf_newface(node, node->next, NULL, env));
				node = node->next;
			}
		}
	}
}

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
			fdf_addface(&MAP(face), fdf_newface(NA, NB, ND, env));
			fdf_addface(&MAP(face), fdf_newface(NB, NC, ND, env));
		}
		else
		{
			fdf_addface(&MAP(face), fdf_newface(NA, NB, NC, env));
			fdf_addface(&MAP(face), fdf_newface(NA, NC, ND, env));
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
		tmp->v.z /= CAM(yratio) / 8;
		//zoom adjustment to fix//
		tmp = tmp->next;
	}
	i = 0;
	node_count = fdf_nodecount(env);
	ft_printf("building faces");
	while (NA && NB && ND && NC && i + MAP(h) < node_count)
	{
		facehelper(i, env);
		ft_printf(!(i++ % 100) ? "." : "");
	}
	fdf_specialfaces(env);
	//read_face(env);
//	fdf_zsortfaces(env);
	ft_printf("\nOK\n");
}
