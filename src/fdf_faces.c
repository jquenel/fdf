/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_faces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:37:43 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 00:13:53 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void			fdf_addface(t_face **face1, t_face *face2)
{
	t_face		*tmp;

	if (!(*face1))
		*face1 = face2;
	else
	{
		tmp = *face1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = face2;
		face2->prev = tmp;
	}
	printf("added a face :\na{%p}[%.1lf][%.1lf][%.1lf]\nb{%p}[%.1lf][%.1lf][%.1lf]\nc{%p}[%.1lf][%.1lf][%.1lf]\n", face2->a, face2->a->v.x, face2->a->v.y, face2->a->v.z,
			face2->b, face2->b->v.x, face2->b->v.y, face2->b->v.z,
			face2->c, face2->c->v.x, face2->c->v.y, face2->c->v.z);
}

void			fdf_fton(t_face *f, t_node *n)
{
	int		i;

	if (!f || !n)
		return ;
	i = 0;
	while ((n->face)[i])
		i++;
	(n->face)[i] = f;
}

t_face			*fdf_newface(t_node *a, t_node *b, t_node *c, t_env *env)
{
	t_face		*face;

	ft_err(!(face = malloc(sizeof(t_face))), ERR_M, 0);
	face->a = a;
	face->b = b ? b : a;
	face->c = c ? c : a;
	face->next = NULL;
	face->prev = NULL;
	face->edge[0] = fdf_addedge(&(MAP(edge)), fdf_newedge(face->a, face->b));
	face->edge[1] = fdf_addedge(&(MAP(edge)), fdf_newedge(face->b, face->c));
	face->edge[2] = fdf_addedge(&(MAP(edge)), fdf_newedge(face->c, face->a));
	fdf_fton(face, a);
	fdf_fton(face, b);
	fdf_fton(face, c);
	return (face);
}
