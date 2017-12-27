/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 08:33:21 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 21:04:02 by jquenel          ###   ########.fr       */
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
		fdf_addpixel((int)x1, (int)y1, C_WHITE, env);
		x1--;
		if ((e -= dy) >= 0)
		{
			y1--;
			e += dx;
		}
	}
	fdf_addpixel((int)x2, (int)y2, C_WHITE, env);
	return (0);
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
		fdf_addpixel((int)x1, (int)y1, C_WHITE, env);
		y1--;
		if ((e -= dx) >= 0)
		{
			x1--;
			e += dy;
		}
	}
	fdf_addpixel((int)x2, (int)y2, C_WHITE, env);
	return (0);
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
		fdf_addpixel((int)x1, (int)y1, C_WHITE, env);
		y1--;
		if ((e += dx) > 0)
		{
			x1++;
			e += dy;
		}
	}
	fdf_addpixel((int)x2, (int)y2, C_WHITE, env);
	return (0);
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
		fdf_addpixel((int)x1, (int)y1, C_WHITE, env);
		x1++;
		if ((e += dy) < 0)
		{
			y1--;
			e += dx;
		}
	}
	return (0);
}
