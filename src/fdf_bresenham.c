/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 07:53:20 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 21:13:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bres1(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		fdf_addpixel(x1, y1, C_WHITE, env);
		x1++;
		if ((e -= dy) < 0)
		{
			y1++;
			e += dx;
		}
	}
	return (0);
}

int		bres2(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = y2 - y1;
	dx = (x2 - x1) *2;
	dy = e * 2;
	while (y1 <= y2)
	{
		fdf_addpixel(x1, y1, C_WHITE, env);
		y1++;
		if ((e -= dx) < 0)
		{
			x1++;
			e += dy;
		}
	}
	return (0);
}

int		bres4(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 >= x2)
	{
		fdf_addpixel(x1, y1, C_WHITE, env);
		x1--;
		if ((e += dy) >= 0)
		{
			y1++;
			e += dx;
		}
	}
	fdf_addpixel(x2, y2, C_WHITE, env);
	return (0);
}

int		bres3(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = y2 - y1;
	dy = e * 2;
	dx = (x2 - x1) * 2;
	while (y1 <= y2)
	{
		fdf_addpixel(x1, y1, C_WHITE, env);
		y1++;
		if ((e += dx) <= 0)
		{
			x1--;
			e += dy;
		}
	}
	fdf_addpixel(x2, y2, C_WHITE, env);
	return (0);
}

int		fdf_bresenham(t_v3d v1, t_v3d v2, t_env *env)
{
	int		dx;
	int		dz;

	v1 = fdf_applymatrices(v1, env);
	v2 = fdf_applymatrices(v2, env);
	if (fdf_outofbounds(v1) && fdf_outofbounds(v2))
		return (0);
	dx = v2.x - v1.x;
	dz = v2.z - v1.z;
	if (dx > 0)
	{
		if (dz > 0)
			return (dx >= dz ? bres1((int)v1.x, (int)v1.z, (int)v2.x,
						(int)v2.z, env) :
					bres2((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
		else
			return (dx >= -dz ? bres8((int)v1.x, (int)v1.z, (int)v2.x,
	(int)v2.z, env) : bres7((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
	}
	else if (dz > 0)
		return (-dx >= dz ? bres4((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z,
				env) : bres3((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
	else
		return (dx <= dz ? bres5((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z,
				env) : bres6((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
}