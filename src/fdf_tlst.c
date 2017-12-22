/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_tlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 12:21:47 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:45:20 by jquenel          ###   ########.fr       */
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
	printf("0301\n");
	lst->next = NULL;
	printf("0302\n");
	return (lst);
}

void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list)
{
	t_tlist		*tmp;

	printf("0303\n");
	if (!(*begin_list))
	{
		*begin_list = list;
		return ;
	}
	tmp = *begin_list;
	printf("0304\n");
	while (tmp->next)
		tmp = tmp->next;
	printf("0305\n");
	tmp->next = list;
}
