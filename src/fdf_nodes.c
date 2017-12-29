/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:15:40 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/29 14:06:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int			fdf_nodecount(t_env *env)
{
	t_node	*tmp;
	int		i;

	tmp = MAP(node);
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_node		*fdf_newnode(t_v3d v)
{
	t_node		*n;
	int			i;

	ft_err(!(n = (t_node *)malloc(sizeof(t_node))), ERR_M, 0);
	n->v.x = v.x;
	n->v.y = v.y;
	n->v.z = v.z;
	n->next = NULL;
	n->prev = NULL;
	i = -1;
	while (++i < MAX_NFACE)
		n->face[i] = NULL;
	return (n);
}

void		fdf_addnode(t_node	**node1, t_node *node2)
{
	t_node		*tmp;

	if (!*node1)
		*node1 = node2;
	else
	{
		tmp = *node1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node2;
		node2->prev = tmp;
	}
}

void		fdf_loadsave(t_env *env)
{
	t_node	*tmp;
	t_node	*save;

	tmp = MAP(node);
	save = MAP(save);
	while (tmp && save)
	{
		tmp->v = save->v;
		tmp = tmp->next;
		save = save->next;
	}
}

void		fdf_savepoint(t_env *env)
{
	t_node	*tmp;

	tmp = MAP(node);
	while (tmp)
	{
		fdf_addnode(&MAP(save), fdf_newnode(tmp->v));
		tmp = tmp->next;
	}
}
