/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:00:01 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:46:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		fdf_init_env(t_env **env)
{
	//ft_errcheck
	*env = (t_env *)malloc(sizeof(t_env));
	(*env)->mlx = mlx_init();
	(*env)->win_fdf = mlx_new_window((*env)->mlx, WIDTH, HEIGHT, "fdf");
	//(*env)->win_help = mlx_new_window((*env)->mlx, 400, 400, "fdf_help");
	(*env)->map = (t_map *)malloc(sizeof(t_map));
	(*env)->map->type = 0;
	(*env)->map->node = NULL;
	(*env)->map->face = NULL;
}

