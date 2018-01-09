/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_cam.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:07:47 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/09 16:38:59 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	init_viewm(t_env *env)
{
	t_v3d	f;
	t_v3d	up;
	t_v3d	s;
	t_v3d	u;

	f = ft_v3d_normalize(ft_v3d_sub(ft_v3d_new(0, 1, 0), CAM(pos)));
	up = ft_v3d_new(0, 0, 1);
	s = ft_v3d_x_v3d(f, up);
	u = ft_v3d_x_v3d(ft_v3d_normalize(s), f);
	//f = ft_v3d_scale(f, -1);
	CAM(viewm) = ft_mx4_new(s, u, f);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("[%d:%d][%.1lf]\n", i, j, CAM(viewm).mat[i][j]);
		}
	}
}

void		fdf_init_camera(t_env *env)
{
	ft_err(!(env->cam = (t_cam *)malloc(sizeof(t_cam))), ERR_M, 0);
	CAM(pos) = ft_v3d_new(CAM_START_X, CAM_START_Y, CAM_START_Z);
	CAM(angle) = ft_v3d_new(CAM_START_RX, CAM_START_RY, CAM_START_RZ);
	CAM(speed) = CAM_START_SPD;
	CAM(yratio) = ZOOM;
	CAM(mode) = CAM_MODE;
	CAM(cmode) = CAM_CMODE;
	init_viewm(env);
	ft_err(!(CAM(img) = (t_img *)malloc(sizeof(t_cam))), ERR_M, 0);
	IMG(ptr) = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG(data) = mlx_get_data_addr(IMG(ptr), &(IMG(bpp)), &(IMG(lsize)),
			&(IMG(endian)));
}


