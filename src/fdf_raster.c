/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_raster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 20:11:12 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/30 01:03:51 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <unistd.h>
#define DET_AB		face->edge->det
#define DET_BC		face->edge->next->det
#define DET_CA		face->edge->next->next->det

static float	min3f(float a, float b, float c)
{
	if (a > b)
		return (b > c ? lround(c) : lround(b));
	return (a > c ? lround(c) : lround(a));
}

static float	max3f(float a, float b, float c)
{
	if (a < b)
		return (b < c ? lround(c) : lround(b));
	return (a < c ? lround(c) : lround(a));
}

int			raster_draw(t_node a, t_node b, t_node c, int i[3], t_env *env)
{
	float	det[3];
	t_v3d	v;

	//printf("rasterdraw\n");
	v.x = i[0];
	v.z = i[2];
	if ((det[0] = fdf_orient2d(a.v, b.v, v)) <= R_TOLERANCE && det[0] >= -R_TOLERANCE)
		fdf_addpixel(i[0], i[2], C_WHITE, env);
	if (c.next == NULL)
	{
		if ((det[1] = fdf_orient2d(b.v, c.v, v)) <= R_TOLERANCE && det[1] >= -R_TOLERANCE)
			fdf_addpixel(i[0], i[2], C_WHITE, env);
		if ((det[2] = fdf_orient2d(c.v, a.v, v)) <= R_TOLERANCE && det[2] >= -R_TOLERANCE)
			fdf_addpixel(i[0], i[2], C_WHITE, env);
	}
	MAP(zmap)[i[0] + i[2] * WIDTH] = (det[0] >= 0 && det[1] >= 0 &&
			det[2] >= 0) ? 1 : 0;
	return (1);
}

void		fdf_raster(t_node a, t_node b, t_node c, t_env *env)
{
	int			i[3];
	int			bound[2];

	//printf("Hello raster\na [%.1lf : %.1lf : %.1lf]\nb [%.1lf : %.1lf : %.1lf]\nc [%.1lf : %.1lf : %.1lf]\n", a.v.x, a.v.y, a.v.z, b.v.x, b.v.y, b.v.z, c.v.x, c.v.y, c.v.z);
	i[0] = (int)(min3f(a.v.x, b.v.x, c.v.x)) - 1;
	bound[0] = (int)(max3f(a.v.x, b.v.x, c.v.x));
	i[1] = (int)(min3f(a.v.z, b.v.z, c.v.z));
	bound[1] = (int)(max3f(a.v.z, b.v.z, c.v.z));
	while (++(i[0]) <= bound[0])
	{
		i[2] = i[1] - 1;
		while (++(i[2]) <= bound[1])
		{
			if (!(MAP(zmap)[i[0] + i[2] * WIDTH]))
				raster_draw(a, b, c, i, env);
		}
	}
	sleep(0);
}
