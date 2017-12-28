/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:01:03 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/28 00:19:26 by jquenel          ###   ########.fr       */
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

# define WIDTH			800
# define HEIGHT			600
# define ZOOM			20
# define CAM_START_X	0
# define CAM_START_Y	0
# define CAM_START_Z	0
# define CAM_START_RX	0
# define CAM_START_RY	0
# define CAM_START_RZ	0
# define CAM_START_SPD	0.1

void		fdf_init_env(t_env **env);
void		fdf_parser(t_env *env, char *arg);
void		fdfer(t_env *env, int fd);
void		fdfractol(t_env *env, char *arg);

int			fdf_keypressed(int keycode, t_env *env);
int			fdf_keyreleased(int keycode, t_env *env);
int			fdf_draw1(t_env *env);
int			fdf_draw2(t_env *env);
void		fdf_addpixel(int x, int y, int c, t_env *env);
void		fdf_move(t_env *env);
t_mx4		fdf_loadmatrix(t_env *env);
int			fdf_applymatrices(t_v3d *v, t_env *env);
t_bool		fdf_outofbounds(t_v3d v);

void		fdf_addnode(t_node **node1, t_node *node2);
t_node		*fdf_newnode(t_v3d v);
int			fdf_nodecount(t_env *env);
void		fdf_addface(t_face **face1, t_face *face2);
t_face		*fdf_newface(t_node *a, t_node *b, t_node *c);
void		read_face(t_env *env);
t_edge		*fdf_newedge(t_node *n1, t_node *n2);
void		fdf_addedge(t_edge **edge1, t_edge *edge2);

t_tlist		*fdf_tlstnew(char **tab);
void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list);

int			fdf_bresenham(t_v3d v1, t_v3d v2, t_env *env);
int			bres1(int x1, int y1, int x2, int y2, t_env *env);
int			bres2(int x1, int y1, int x2, int y2, t_env *env);
int			bres3(int x1, int y1, int x2, int y2, t_env *env);
int			bres4(int x1, int y1, int x2, int y2, t_env *env);
int			bres5(int x1, int y1, int x2, int y2, t_env *env);
int			bres6(int x1, int y1, int x2, int y2, t_env *env);
int			bres7(int x1, int y1, int x2, int y2, t_env *env);
int			bres8(int x1, int y1, int x2, int y2, t_env *env);

#endif
