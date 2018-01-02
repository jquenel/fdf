/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:00:01 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/31 16:05:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		fdf_init_camera(t_env *env)
{
	ft_err(!(env->cam = (t_cam *)malloc(sizeof(t_cam))), ERR_M, 0);
	CAM(pos) = ft_v3d_new(CAM_START_X, CAM_START_Y, CAM_START_Z);
	CAM(angle) = ft_v3d_new(CAM_START_RX, CAM_START_RY, CAM_START_RZ);
	CAM(speed) = CAM_START_SPD;
	CAM(yratio) = ZOOM;
	CAM(mode) = CAM_MODE;
	ft_err(!(CAM(img) = (t_img *)malloc(sizeof(t_cam))), ERR_M, 0);
	IMG(ptr) = mlx_new_image(MLX, WIDTH, HEIGHT);
	IMG(data) = mlx_get_data_addr(IMG(ptr), &(IMG(bpp)), &(IMG(lsize)),
			&(IMG(endian)));
}

void		fdf_init_map(t_env *env)
{
	ft_err(!(env->map = malloc(sizeof(t_map))), ERR_M, 0);
//	ft_err(!(env->map->zmap = malloc(sizeof(int) * WIDTH * HEIGHT)), ERR_M, 0);
	ft_bzero(MAP(zmap), WIDTH * HEIGHT * sizeof(int));
	MAP(type) = 0;
	MAP(w) = 0;
	MAP(h) = 0;
	MAP(node) = NULL;
	MAP(save) = NULL;
	MAP(face) = NULL;
	ft_bzero(MAP(zmap), WIDTH * HEIGHT);
}

void		fdf_init_env(t_env **env)
{
	//ft_errcheck
	ft_err(!(*env = (t_env *)malloc(sizeof(t_env))), ERR_M, 0);
	(*env)->mlx = mlx_init();
	(*env)->win_fdf = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "fdf");
	(*env)->win_help = NULL;
	(*env)->keymap = 0x0;
	//(*env)->win_help = mlx_new_window((*env)->mlx, 400, 400, "fdf_help");
	fdf_init_map(*env);
	fdf_init_camera(*env);
}
