/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:44:54 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_draw2(t_env *env)
{
	t_node		*node;
	int			dx;
	int			dy;

	dx = WIDTH / 2 - env->map->w;
	dy = HEIGHT / 2 - env->map->h;
	node = env->map->node;
	while (node)
	{
		mlx_pixel_put(MLX, WIN, node->v.x + dx, node->v.y + dy, 0x00FFFFFF);
		node = node->next;
	}
	return (1);
}
