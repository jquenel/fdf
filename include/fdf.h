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

#ifndef FDF_H
# define FDF_H

# include "libmat.h"
# include "fdftypes.h"
# include "libft.h"
# include <mlx.h>

#include <stdio.h>

# define WIDTH		600
# define HEIGHT		400
# define ZOOM		10

void		fdf_init_env(t_env **env);
void		fdf_parser(t_env *env, char *arg);
void		fdfer(t_env *env, int fd);
void		fdfractol(t_env *env, char *arg);

int			fdf_draw1(t_env *env);
int			fdf_draw2(t_env *env);

void		fdf_addnode(t_node **node, t_v3d v);
t_tlist		*fdf_tlstnew(char **tab);
void		fdf_tlstpushback(t_tlist **begin_list, t_tlist *list);

#endif
