/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:21:47 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/02 19:16:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_tlist		*fdf_tlstnew(char **tab)
{
	t_tlist		*lst;

	if (!(lst = malloc(sizeof(t_tlist))))
		return (NULL);
	lst->tab = tab;
	lst->next = NULL;
	return (lst);
}

void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list)
{
	t_tlist		*tmp;

	if (!(*begin_list))
	{
		*begin_list = list;
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = list;
}
