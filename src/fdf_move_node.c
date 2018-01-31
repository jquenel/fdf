/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_store_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:52:31 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 20:13:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_move_node(t_node **dst_lst, t_node **src_lst, t_node *n)
{
	t_node	*tmp;

	tmp = *src_lst;
	while (tmp && tmp != n)
		tmp = tmp->next;
	ft_err(!tmp, "Did not found node in map", 0);
	if (tmp->next)
		tmp->next->prev = NULL;
	if (!tmp->prev)
		*src_lst = tmp->next;
	else
		tmp->prev->next = tmp->next;
	tmp->next = NULL;
	fdf_addnode(dst_lst, tmp);
}
