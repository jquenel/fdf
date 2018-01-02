/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:50:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/31 17:03:31 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFTYPES_H
# define FDFTYPES_H

# include "libmat.h"
# include <inttypes.h>

# define MLX		env->mlx
# define WIN		env->win_fdf
# define WINH		env->win_help
# define CAM(x)		(env->cam->x)
# define IMG(x)		(CAM(img)->x)
# define MAP(x)		(env->map->x)

# define MAX_NFACE		16
# define WIDTH			1600
# define HEIGHT			1000
# define ZOOM			20
# define CAM_START_X	0
# define CAM_START_Y	20
# define CAM_START_Z	0
# define CAM_START_RX	M_PI / -3
# define CAM_START_RY	0
# define CAM_START_RZ	M_PI / -2
# define CAM_START_SPD	0.1
# define CAM_MODE		0
# define R_TOLERANCE	20

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
	float			det;
	struct s_edge	*next;
}						t_edge;

typedef struct			s_face
{
	t_edge			*edge;
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*c;
	float			depth;
	struct s_face	*next;
	struct s_face	*prev;
}						t_face;

typedef struct			s_node
{
	t_v3d			v;
	t_v3d			dv;
	t_face			*face[MAX_NFACE];
	float			height;
	struct s_node	*next;
	struct s_node	*prev;
}						t_node;

typedef struct			s_map
{
	int				type;
	int				w;
	int				h;
	int				zmap[WIDTH * HEIGHT];
	t_node			*node;
	t_node			*save;
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
	t_mx4			viewm;
	t_img			*img;
	float			speed;
	float			yratio;
	int				mode;
	int				color;
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
#  define FK_T		0x11
#  define FK_N0		0x52
#  define FK_N1		0x53
#  define FK_N2		0x54
#  define FK_N3		0x55
#  define FK_N4		0x56
#  define FK_N5		0x57
#  define FK_N6		0x58
#  define FK_N7		0x59
#  define FK_N8		0x5b
#  define FK_N9		0x5c
#  define FK_NPLUS	0x45
#  define FK_NMINUS	0x4e

# endif

# ifndef FDF_KEYMAP
#  define FDF_KEYMAP

#  define FM_UP		(1L << 1)
#  define FM_DOWN	(1L << 2)
#  define FM_LEFT	(1L << 3)
#  define FM_RIGHT	(1L << 4)
#  define FM_W		(1L << 5)
#  define FM_A		(1L << 6)
#  define FM_S		(1L << 7)
#  define FM_D		(1L << 8)
#  define FM_T		(1L << 21)
#  define FM_N0		(1L << 9)
#  define FM_N1		(1L << 10)
#  define FM_N2		(1L << 11)
#  define FM_N3		(1L << 12)
#  define FM_N4		(1L << 13)
#  define FM_N5		(1L << 14)
#  define FM_N6		(1L << 15)
#  define FM_N7		(1L << 16)
#  define FM_N8		(1L << 17)
#  define FM_N9		(1L << 18)
#  define FM_NPLUS	(1L << 19)
#  define FM_NMINUS	(1L << 20)

# endif

# ifndef FDF_COLORS
#  define FDF_COLORS

#  define C_WHITE		0x00ffffff
#  define C_RED			0xff000000
#  define C_GREEN		0x00ff0000
#  define C_BLUE		0x0000ff00
#  define C_BLACK		0x0

typedef union			u_color
{
	int32_t			i;
	unsigned char	c[4];
}						t_color;

# endif

#endif
