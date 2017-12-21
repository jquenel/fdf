/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdftypes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:50:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/21 19:36:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFTYPES_H
# define FDFTYPES_H

# include "libmat.h"

/*
**		Faces should always be triangles.
**		Directional edges are implicit : ab, bc, ca.
**		When a face is created, these are ordered so that their determinant
		should be superior or equal to 0 when computed in that order.
*/

typedef struct			s_face
{
	struct s_node	*a;
	struct s_node	*b;
	struct s_node	*c;
	struct s_face	*next;
}						t_face;

typedef struct			s_node
{
	t_v3d			v;
	t_face			*faces;
	struct s_node	*next;
	struct s_node	*prev;
}						t_node;

typedef struct			s_map
{
	t_node			*nodes;
	t_face			*faces;
}						t_map;

typedef struct			s_env
{
	t_map			map;
}						t_env;

#endif
