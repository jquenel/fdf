/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:50:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 11:46:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFTYPES_H
# define FDFTYPES_H

# include "fdf.h"
# include "libmat.h"
# include <inttypes.h>

# define MLX		env->mlx
# define WIN		env->win_fdf
# define WINH		env->win_help
# define CAM(x)		(env->cam->x)
# define IMG(x)		(CAM(img)->x)
# define MAP(x)		(env->map->x)
# define MAX_NFACE	16


# ifndef ERR_CODES
#  define ERR_CODES

#  define ERR_M		"Malloc error."

# endif

# ifndef T_BOOL
#  define T_BOOL
typedef int				t_bool;
#  define TRUE		1
#  define FALSE		0
# endif
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
	struct s_face	*prev;
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

typedef struct			s_img
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				lsize;
	int				endian;
}						t_img;

typedef struct			s_cam
{
	t_v3d			pos;
	t_v3d			angle;
	t_v3d			focal;
	t_img			*img;
	float			speed;
}						t_cam;

typedef struct			s_env
{
	void			*mlx;
	void			*win_fdf;
	void			*win_help;
	t_map			*map;
	t_cam			*cam;
	int32_t			keymap;
}						t_env;

typedef struct			s_tlist
{
	char			**tab;
	struct s_tlist	*next;
}						t_tlist;

# ifndef FDF_KEYCODES
#  define FDF_KEYCODES

#  define FK_ESC	0x35
#  define FK_UP		0x7e
#  define FK_DOWN	0x7d
#  define FK_LEFT	0x7b
#  define FK_RIGHT	0x7c
#  define FK_W		0xd
#  define FK_A		0x0
#  define FK_S		0x1
#  define FK_D		0x2

# endif

# ifndef FDF_KEYMAP
#  define FDF_KEYMAP

#  define FM_ESC	(1L)
#  define FM_UP		(1L << 1)
#  define FM_DOWN	(1L << 2)
#  define FM_LEFT	(1L << 3)
#  define FM_RIGHT	(1L << 4)
#  define FM_W		(1L << 5)
#  define FM_A		(1L << 6)
#  define FM_S		(1L << 7)
#  define FM_D		(1L << 8)

# endif

# ifndef FDF_COLORS
#  define FDF_COLORS

#  define C_WHITE		0xffffff00
#  define C_RED			0xff000000
#  define C_GREEN		0x00ff0000
#  define C_BLUE		0x0000ff00

typedef union			u_color
{
	int32_t		i;
	char		c[4];
}						t_color;

# endif

#endif
