/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:01:03 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/11 21:45:18 by jquenel          ###   ########.fr       */
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

void		fdf_init_env(t_env **env);
void		fdf_init_camera(t_env *env);
void		fdf_parser(t_env *env, char *arg);
void		fdfer(t_env *env, int fd);
void		fdfractol(t_env *env);
void		fdf_fildefractol(t_finfos *cloud, t_env *env);

int			fdf_keypressed(int keycode, t_env *env);
int			fdf_keyreleased(int keycode, t_env *env);
int			fdf_buttonpress(int button, int x, int y, t_env *env);
void		fdf_move(t_env *env);
void		fdf_reinitcam(t_env *env);

int			fdf_draw_fractol(t_env *env);
int			fdf_draw_fdf(t_env *env);
int			fdf_draw_hlr(t_env *env);
void		fdf_raster(t_node *a, t_node *b, t_node *c, t_env *env);
float		fdf_orient2d(t_v3d a, t_v3d b, t_v3d c);
void		fdf_addpixel(int x, int y, int c, t_env *env);

void		fdf_loadmatrix(t_env *env);
int			fdf_applymatrices(t_env *env);
t_mx4		fdf_rot(t_v3d pos, double t, t_mx4 (*f)(double));
t_bool		fdf_outofbounds(t_v3d v);

void		fdf_zsort(t_env *env);
void		fdf_zsortfaces(t_env *env);

void		fdf_addnode(t_node **node1, t_node *node2);
t_node		*fdf_newnode(t_v3d v);
int			fdf_nodecount(t_env *env);
void		fdf_get_nlist(t_env *env);

void		fdf_addface(t_face **face1, t_face *face2);
t_face		*fdf_newface(t_node *a, t_node *b, t_node *c, t_env *env);
void		fdf_facebuilder(t_env *env);
void		read_face(t_env *env);

t_edge		*fdf_newedge(t_node *n1, t_node *n2);
t_edge		*fdf_addedge(t_edge **edge1, t_edge *edge2);
void		fdf_clearzmapedges(t_env *env);

t_tlist		*fdf_tlstnew(char **tab);
void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list);

int			fdf_bresenham(t_v3d v1, t_v3d v2, t_env *env);
int			fdf_bres_limits(t_v3d a, t_v3d b, t_env *env);
int			bres1(int x1, int y1, int x2, int y2, t_env *env);
int			bres2(int x1, int y1, int x2, int y2, t_env *env);
int			bres3(int x1, int y1, int x2, int y2, t_env *env);
int			bres4(int x1, int y1, int x2, int y2, t_env *env);
int			bres5(int x1, int y1, int x2, int y2, t_env *env);
int			bres6(int x1, int y1, int x2, int y2, t_env *env);
int			bres7(int x1, int y1, int x2, int y2, t_env *env);
int			bres8(int x1, int y1, int x2, int y2, t_env *env);

#endif
