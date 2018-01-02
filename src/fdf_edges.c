/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_edges.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 23:40:44 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/02 19:16:48 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_edge			*fdf_newedge(t_node *n1, t_node *n2)
{
	t_edge		*edge;

	//checkerror
	edge = malloc(sizeof(t_edge));
	edge->n1 = n1;
	edge->n2 = n2;
	edge->next = NULL;
	edge->drawn = 0;
	return (edge);
}

void			fdf_clearzmapedges(t_env *env)
{
	t_edge	*edge;

	edge = MAP(edge);
	while (edge)
	{
		edge->drawn = 0;
		edge = edge->next;
	}
	bzero(MAP(zmap), WIDTH * HEIGHT * sizeof(int));
}

t_edge			*fdf_addedge(t_edge **edge1, t_edge *edge2)
{
	t_edge	*tmp;

	if (!(*edge1))
	{
		*edge1 = edge2;
		return (edge2);
	}
	else
	{
		tmp = *edge1;
		while (tmp)
		{
			if ((tmp->n1 == edge2->n1 && tmp->n2 == edge2->n2) ||
				(tmp->n2 == edge2->n1 && tmp->n1 == edge2->n2))
				return (tmp);
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp->next = edge2;
		return (edge2);
	}
}
