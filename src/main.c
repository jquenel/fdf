/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:21 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 17:25:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X.h>
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
	mlx_hook(WIN, KeyPress, KeyPressMask, fdf_keypressed, env);
	mlx_hook(WIN, KeyRelease, KeyReleaseMask, fdf_keyreleased, env);
	mlx_loop_hook(MLX, fdf_draw2, env);
	printf("3\n");
	printf("wat\n");
	mlx_loop(MLX);
	return (argc);
}
