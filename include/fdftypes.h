/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:50:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:44:02 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFTYPES_H
# define FDFTYPES_H

# include "fdf.h"
# include "libmat.h"

# define MLX		env->mlx
# define WIN		env->win_fdf
# define WINH		env->win_help
# define CAM(x)		(env->cam->x)
# define MAP(x)		(env->map->x)
# define MAX_NFACE	16

/*
**		Faces should always be triangles.
**		Directional edges are implicit : ab, bc, ca.
**		When a face is created, these are ordered so that their determinant
		should be superior or equal to 0 when computed in that order.
*/

typedef struct			s_edge
{
	struct s_node	*n1;
	struct s_node	*n2;
	struct s_edge	*next;
}						t_edge;

typedef struct			s_face
{
	t_edge			*edge;
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*c;
	struct s_face	*next;
}						t_face;

typedef struct			s_node
{
	t_v3d			v;
	t_face			*face[MAX_NFACE];
	struct s_node	*next;
	struct s_node	*prev;
}						t_node;

typedef struct			s_map
{
	int				type;
	int				w;
	int				h;
	t_node			*node;
	t_node			**nlist;
	t_face			*face;
}						t_map;

typedef struct			s_cam
{
	t_v3d			pos;
	t_v3d			angle;
	t_v3d			focal;
	float			speed;
}						t_cam;

typedef struct			s_env
{
	void			*mlx;
	void			*win_fdf;
	void			*win_help;
	t_map			*map;
	t_cam			*cam;
}						t_env;

typedef struct			s_tlist
{
	char			**tab;
	struct s_tlist	*next;
}						t_tlist;

#endif
