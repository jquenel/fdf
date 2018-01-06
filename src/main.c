/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:00:21 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/04 21:51:07 by jquenel          ###   ########.fr       */
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
	mlx_hook(WIN, ButtonPress, Button1Mask, fdf_buttonpress, env);
	mlx_loop_hook(MLX, MAP(type) == 2 ? fdf_draw_fdf : fdf_draw_fractol, env);
	printf("3\n");
	printf("wat\n");
	mlx_loop(MLX);
	return (argc);
}
