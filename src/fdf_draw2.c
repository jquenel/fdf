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


#include <unistd.h>
int			fdf_draw2(t_env *env)
{
	t_node		*node;
	t_mx4		viewm;
	t_v3d		v;

	mlx_clear_window(MLX, WIN);
	viewm = fdf_loadmatrix(env);
	//env->cam->angle.z += 0.00001;
	//env->cam->angle.x += 0.0001;
	//printf("viewm : [00 : %.2lf] [01 : %.2lf] [02 : %.2lf] [03 : %.2lf]\n", viewm.mat[0][0],
//	viewm.mat[0][1], viewm.mat[0][2], viewm.mat[0][3]);
	//printf("040\n");
	node = env->map->node;
	while (node)
	{
		//v = ft_v3d_x_mx4(node->v, ft_mx4_transl(CAM(pos)));
		v = ft_v3d_x_mx4(node->v, xrot_mx4(CAM(angle.x)));
		v = ft_v3d_x_mx4(v, yrot_mx4(CAM(angle.y)));
		v = ft_v3d_x_mx4(v, zrot_mx4(CAM(angle.z)));
		//printf("[x : %.2lf][y : %.2lf][z : %.2lf]\n", v.x, v.y, v.z);
		mlx_pixel_put(MLX, WIN, v.x * ZOOM + WIDTH / 2, v.z * ZOOM + HEIGHT / 2,
				0x00FFFFFF - node->v.z * 0x000000FF);
		node = node->next;
	}
	sleep(0);
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
