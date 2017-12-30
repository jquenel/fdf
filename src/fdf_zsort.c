/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 01:21:19 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/29 18:23:17 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			fdf_zsort(t_env *env)
{
	(void)env;
}

void			fdf_swapfaces(t_face *f1, t_face *f2)
{
	f1->prev->next = f2;
	f2->prev = f1->prev;
	f1->prev = f2;
	f1->next = f2->next;
	f2->next->prev = f1;
	f2->next = f1;
}

static float	min3f(float a, float b, float c)
{
	if (a > b)
		return (b > c ? c : b);
	return (a > c ? c : a);
}

void			fdf_zsortfaces(t_env *env)
{
	t_face		*tmp;
	t_face		*cur;

	cur = MAP(face);
	while (cur)
	{
		cur->depth = min3f(cur->a->v.y, cur->b->v.y, cur->c->v.y);
		cur = cur->next;
	}
	cur = MAP(face);
	while (cur)
	{
		tmp = cur;
		while (tmp->prev && tmp->depth < tmp->prev->depth)
			fdf_swapfaces(tmp->prev, tmp);
		if (!(tmp->prev))
			MAP(face) = tmp;
		cur = cur->next;
	}
	tmp = MAP(face);
	/*while (tmp)
	{
		printf("y:[%3.1f]\n", min3f(tmp->a->v.y, tmp->b->v.y, tmp->c->v.y));
		tmp = tmp->next;
	}*/
}
