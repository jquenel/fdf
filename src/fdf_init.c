/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:00:01 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/30 02:23:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

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

void		fdf_init_fal(t_env *env)
{
	ft_err(!(env->fal = malloc(sizeof(t_fal))), ERR_M, 0);
	FAL(npool) = NULL;
	FAL(fpool) = NULL;
	FAL(center)[0] = FAL_WC;
	FAL(center)[1] = FAL_HC;
	FAL(w) = FAL_W;
	FAL(h) = FAL_H;
	FAL(lx) = FAL(center)[0] - FAL(w) / 2;
	FAL(hx) = FAL(center)[0] + FAL(w) / 2;
	FAL(ly) = FAL(center)[1] - FAL(h) / 2;
	FAL(hy) = FAL(center)[1] + FAL(h) / 2;
	FAL(start)[0] = FAL(lx);
	FAL(start)[1] = FAL(hx);
	FAL(start)[2] = FAL(ly);
	FAL(start)[3] = FAL(hy);
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
	fdf_init_fal(*env);
}
