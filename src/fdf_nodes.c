/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:15:40 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/06 21:08:34 by jquenel          ###   ########.fr       */
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
	n->v = ft_v3d_new(v.x, v.y, v.z);
	n->dv = ft_v3d_new(v.x, v.y, v.z);
	n->fvalue = 0;
	n->lit = TRUE;
	n->next = NULL;
	n->prev = NULL;
	i = -1;
	while (++i < MAX_NFACE)
		n->face[i] = NULL;
	return (n);
}

void		fdf_addnode(t_node **node1, t_node *node2)
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

void		fdf_reinitcam(t_env *env)
{
	CAM(pos) = ft_v3d_new(CAM_START_X, CAM_START_Y, CAM_START_Z);
	CAM(angle) = ft_v3d_new(CAM_START_RX, CAM_START_RY, CAM_START_RZ);
	CAM(speed) = CAM_START_SPD;
	CAM(yratio) = ZOOM;
}
