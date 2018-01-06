/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_buttonpress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:51:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/04 22:23:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_buttonpress(int button, int x, int y, t_env *env)
{
	printf("[%d : %d]\n", x, y);
	if (MAP(type) == 1)
	{
		FAL(w) -= FAL(w) * FAL_ZOOM;
		FAL(h) -= FAL(h) * FAL_ZOOM;
		FAL(center)[0] += (x - WIDTH / 2) * (FAL(w)) / WIDTH;
		FAL(center)[1] += (y - HEIGHT / 2) * (FAL(h)) / HEIGHT;
		FAL(lx) = FAL(center)[0] - FAL(w) / 2;
		FAL(hx) = FAL(center)[0] + FAL(w) / 2;
		FAL(ly) = FAL(center)[1] - FAL(h) / 2;
		FAL(hy) = FAL(center)[1] + FAL(h) / 2;
	}
	return (0);
}
