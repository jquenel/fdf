/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:21 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:45:31 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int			main(int argc, char **argv)
{
	t_env	*env;

	//ft_errcheck("", (argc != 2));
	printf("0\n");
	fdf_init_env(&env);
	printf("1\n");
	fdf_parser(env, argv[1]);
	printf("2\n");
	mlx_key_hook(WIN, fdf_keyevent, env);
	mlx_loop_hook(MLX, env->map->type == 1 ? fdf_draw1 : fdf_draw2, env);
	printf("3\n");
	mlx_loop(MLX);
	return (argc);
}
