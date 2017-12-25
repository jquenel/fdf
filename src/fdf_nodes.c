/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:15:40 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:51:13 by jquenel          ###   ########.fr       */
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

void		fdf_addnode(t_node	**node, t_v3d v)
{
	t_node		*fresh;
	t_node		*tmp;
	int			i;

	tmp = *node;
	//ft_errcheck
	fresh = malloc(sizeof(t_node));
	ft_v3d_copy(&(fresh->v), v);
	i = 0;
	while (i < MAX_NFACE)
		fresh->face[i++] = NULL;
	fresh->next = NULL;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		tmp->next = fresh;
		fresh->prev = tmp;
	}
	else
		*node = fresh;
}
