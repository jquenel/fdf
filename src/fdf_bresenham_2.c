/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 08:33:21 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/06 21:10:05 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		bres5(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;;
	while (x1 >= x2)
	{
		fdf_addpixel((int)x1, (int)y1, CAM(color), env);
		x1--;
		if ((e -= dy) >= 0)
		{
			y1--;
			e += dx;
		}
	}
	fdf_addpixel((int)x2, (int)y2, CAM(color), env);
	return (1);
}

int		bres6(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = y2 - y1;
	dy = e * 2;
	dx = (x2 - x1) * 2;
	while (y1 >= y2)
	{
		fdf_addpixel((int)x1, (int)y1, CAM(color), env);
		y1--;
		if ((e -= dx) >= 0)
		{
			x1--;
			e += dy;
		}
	}
	fdf_addpixel((int)x2, (int)y2, CAM(color), env);
	return (1);
}

int		bres7(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = y2 - y1;
	dy = e * 2;
	dx = (x2 - x1) * 2;
	while (y1 >= y2)
	{
		fdf_addpixel((int)x1, (int)y1, CAM(color), env);
		y1--;
		if ((e += dx) > 0)
		{
			x1++;
			e += dy;
		}
	}
	fdf_addpixel((int)x2, (int)y2, CAM(color), env);
	return (1);
}

int		bres8(int x1, int y1, int x2, int y2, t_env *env)
{
	int		e;
	int		dx;
	int		dy;

	e = x2 - x1;
	dx = e * 2;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		fdf_addpixel((int)x1, (int)y1, CAM(color), env);
		x1++;
		if ((e += dy) < 0)
		{
			y1--;
			e += dx;
		}
	}
	return (1);
}

int		fdf_bres_limits(t_v3d a, t_v3d b, t_env *env)
{
	if (fdf_outofbounds(a) && fdf_outofbounds(b))
		return (1);
	if (a.y > CAM(pos.y) + CAM_START_Y || a.y <= 0.1 ||
	b.y > CAM(pos.y) + CAM_START_Y || b.y <= 0.1)
		return (1);
	return (0);
}
