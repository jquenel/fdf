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

void		fdf_addnode(t_node	**node, t_v3d v)
{
	t_node		*fresh;
	t_node		*tmp;

	tmp = *node;
	//ft_errcheck
	fresh = malloc(sizeof(t_node));
	ft_v3d_copy(&(fresh->v), v);
	fresh->face = NULL;
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
