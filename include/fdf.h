/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:01:03 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:54:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//replace the flags in libft

#ifndef FDF_H
# define FDF_H

# include "libmat.h"
# include "fdftypes.h"
# include "libft.h"
# include <mlx.h>
# include <math.h>

# define XK_MISCELLANY
# include <keysymdef.h>

#include <stdio.h>

# define WIDTH			600
# define HEIGHT			400
# define ZOOM			20
# define CAM_START_X	0
# define CAM_START_Y	0
# define CAM_START_Z	0
# define CAM_START_RX	M_PI + M_PI / 6
# define CAM_START_RY	0
# define CAM_START_RZ	M_PI / 6

void		fdf_init_env(t_env **env);
void		fdf_parser(t_env *env, char *arg);
void		fdfer(t_env *env, int fd);
void		fdfractol(t_env *env, char *arg);

int			fdf_keyevent(int keycode, t_env *env);
int			fdf_draw1(t_env *env);
int			fdf_draw2(t_env *env);
t_mx4		fdf_loadmatrix(t_env *env);

void		fdf_addnode(t_node **node, t_v3d v);
int			fdf_nodecount(t_env *env);
void		fdf_addface(t_face **face1, t_face *face2);
t_face		*fdf_newface(t_node *a, t_node *b, t_node *c);

t_tlist		*fdf_tlstnew(char **tab);
void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list);

#endif
