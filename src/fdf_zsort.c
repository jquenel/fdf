/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 01:21:19 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/02 13:08:40 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <sys/time.h>
void			fdf_swapfaces(t_face *f1, t_face *f2)
{
	if (f1->prev)
		f1->prev->next = f2;
	f2->prev = f1->prev;
	f1->prev = f2;
	f1->next = f2->next;
	if (f2->next)
		f2->next->prev = f1;
	f2->next = f1;
}

static float	min3f(float a, float b, float c)
{
	if (a > b)
		return (b > c ? c : b);
	return (a > c ? c : a);
}

static float	max3f(float a, float b, float c)
{
	if (a > b)
		return (a > c ? a : c);
	return (b > c ? b : c);
}

static float	mid3f(float a, float b, float c)
{
	if (a > b)
	{
		if (a <= c)
			return (a);
		return (b > c ? b : c);
	}
	else
	{
		if (b <= c)
			return (b);
		return (a > c ? a : c);
	}
}
/*
static int		iscloser(t_face *a, t_face *b)
{
	float	diff[3];
	float	a_mag[3];
	float	b_mag[3];

	a_mag[0] = ft_v3d_mag(a->a->dv);
	a_mag[1] = ft_v3d_mag(a->b->dv);
	a_mag[2] = ft_v3d_mag(a->c->dv);
	b_mag[0] = ft_v3d_mag(b->a->dv);
	b_mag[1] = ft_v3d_mag(b->b->dv);
	b_mag[2] = ft_v3d_mag(b->c->dv);
	if (!(diff[0] = min3f(a_mag[0], a_mag[1], a_mag[2]) -
				min3f(b_mag[0], b_mag[1], b_mag[2])))
	{
		if (!(diff[1] = mid3f(a_mag[0], a_mag[1], a_mag[2]) -
				mid3f(b_mag[0], b_mag[1], b_mag[2])))
			return (max3f(a_mag[0], a_mag[1], a_mag[2]) <
					max3f(b_mag[0], b_mag[1], b_mag[2]) ? 1 : 0);
		return (diff[1] < 0 ? 1 : 0);
	}
	return (diff[0] < 0 ? 1 : 0);
}
*/

static int		iscloser(t_face *a, t_face *b)
{
	float	diff[2];

	if (!(diff[0] = min3f(a->a->dv.y, a->b->dv.y, a->c->dv.y) -
				min3f(b->a->dv.y, b->b->dv.y, b->c->dv.y)))
	{
		if (!(diff[1] = max3f(a->a->dv.y, a->b->dv.y, a->c->dv.y) -
					max3f(b->a->dv.y, b->b->dv.y, b->c->dv.y)))
			return (mid3f(a->a->dv.y, a->b->dv.y, a->c->dv.y) <
					mid3f(b->a->dv.y, b->b->dv.y, b->c->dv.y) ? 1 : 0);
		return (diff[1] < 0 ? 1 : 0);
	}
	return (diff[0] < 0 ? 1 : 0);
}

/*
int			iscloser(t_face *a, t_face *b)
{
	t_v3d	normal;

	if (min3f(a->a->v.y, a->b->v.y, a->c->v.y) >
			min3f(b->a->v.y, b->b->v.y, b->c->v.y))
		return (0);
	if (min3f(a->a->v.y, a->b->v.y, a->c->v.y) <
			min3f(b->a->v.y, b->b->v.y, b->c->v.y))
		return (1);
	normal = ft_v3d_x_v3d(ft_v3d_sub(a->a->dv, a->b->dv),
			ft_v3d_sub(a->b->dv, a->c->dv));
	if (ft_v3d_dot(normal, ft_v3d_sub(b->a->v, a->b->v)) < 0 &&
	ft_v3d_dot(normal, ft_v3d_sub(b->b->v, a->b->v)) < 0 &&
	ft_v3d_dot(normal, ft_v3d_sub(b->c->v, a->b->v)) < 0)
		return (1);
	return (0);
}
*/
void			fdf_zsortfaces(t_env *env)
{
	t_face		*tmp;
	t_face		*cur;
	struct timeval stop, start;

	gettimeofday(&start, NULL);
	/*cur = MAP(face);
	while (cur)
	{
		cur->depth = max3f(ft_v3d_mag(cur->a->dv), ft_v3d_mag(cur->b->dv),
				ft_v3d_mag(cur->c->dv));
		cur = cur->next;
	}*/
	cur = MAP(face);
	while (cur)
	{
		tmp = cur;
		while (tmp->prev && iscloser(tmp, tmp->prev))
		{
			fdf_swapfaces(tmp->prev, tmp);
		}
		if (!(tmp->prev))
			MAP(face) = tmp;
		cur = cur->next;
	}
	gettimeofday(&stop, NULL);
	printf("time took : %u\n", stop.tv_usec - start.tv_usec);
	tmp = MAP(face);
	/*while (tmp)
	{
		printf("y:[%3.1f]\n", min3f(tmp->a->dv.y, tmp->b->dv.y, tmp->c->dv.y));
		tmp = tmp->next;
	}*/
}
