/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 11:24:06 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 13:01:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_draw2(t_env *env)
{
	t_node		*node;

	//printf("040\n");
	node = env->map->node;
	while (node)
	{
	printf("041\n");
		mlx_pixel_put(MLX, WIN,
				(node->v.x - env->map->w / 2) * ZOOM + WIDTH / 2,
				(node->v.y - env->map->h / 2) * ZOOM + HEIGHT / 2,
				0x00FFFFFF - 0x0000FFFF * node->v.z);
		node = node->next;
	}
	return (1);
}

void		fdfractol(t_env *env, char *arg)
{
	(void)env;
	(void)arg;
}

int			fdf_draw1(t_env *env)
{
	(void)env;
	return (0);
}
