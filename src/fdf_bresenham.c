/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 07:53:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/06 21:10:26 by jquenel          ###   ########.fr       */
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
		fdf_addpixel(x1, y1, CAM(color), env);
		x1++;
		if ((e -= dy) < 0)
		{
			y1++;
			e += dx;
		}
	}
	return (1);
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
		fdf_addpixel(x1, y1, CAM(color), env);
		y1++;
		if ((e -= dx) < 0)
		{
			x1++;
			e += dy;
		}
	}
	return (1);
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
		fdf_addpixel(x1, y1, CAM(color), env);
		x1--;
		if ((e += dy) >= 0)
		{
			y1++;
			e += dx;
		}
	}
	fdf_addpixel(x2, y2, CAM(color), env);
	return (1);
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
		fdf_addpixel(x1, y1, CAM(color), env);
		y1++;
		if ((e += dx) <= 0)
		{
			x1--;
			e += dy;
		}
	}
	fdf_addpixel(x2, y2, CAM(color), env);
	return (1);
}

int		fdf_bresenham(t_v3d v1, t_v3d v2, t_env *env)
{
	int		dx;
	int		dz;

	CAM(color) = CAM(mode) ? C_BLACK : C_WHITE;
	if (fdf_bres_limits(v1, v2, env))
		return (0);
	if ((dx = v2.x - v1.x) > 0)
	{
		if ((dz = v2.z - v1.z) > 0)
			return (dx >= dz ? bres1((int)v1.x, (int)v1.z, (int)v2.x,
						(int)v2.z, env) :
					bres2((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
		else
			return (dx >= -dz ? bres8((int)v1.x, (int)v1.z, (int)v2.x,
	(int)v2.z, env) : bres7((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
	}
	else if ((dz = v2.z - v1.z) > 0)
		return (-dx >= dz ? bres4((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z,
				env) : bres3((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
	else
		return (dx <= dz ? bres5((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z,
				env) : bres6((int)v1.x, (int)v1.z, (int)v2.x, (int)v2.z, env));
}
