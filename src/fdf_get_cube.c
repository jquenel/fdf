/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:27:16 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 19:48:39 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

#define IJK		i + j * FAL_SIZE + k * FAL_SIZE * FAL_SIZE
#define FS		FAL_SIZE
#define FSS		FAL_SIZE * FAL_SIZE

static char		companion_cube(t_node **cn)
{
	return ((cn[0] ? cn[0]->active * 128 : 0) +
			(cn[1] ? cn[1]->active * 64 : 0) +
			(cn[2] ? cn[2]->active * 32 : 0) +
			(cn[3] ? cn[3]->active * 16 : 0) +
			(cn[4] ? cn[4]->active * 8 : 0) +
			(cn[5] ? cn[5]->active * 4 : 0) +
			(cn[6] ? cn[6]->active * 2 : 0) +
			(cn[7] ? cn[7]->active : 0));
}

static int		isactive(int i, int j, int k, t_node **nlist)
{
	if (i < 0 || j < 0 || k < 0 ||
		i >= FAL_SIZE || j >= FAL_SIZE || k >= FAL_SIZE)
		return (0);
	return (nlist[IJK]->active);
}

void			companion_nodes(int i, int j, int k, t_node **nlist,
								t_node **cn)
{
	printf("getting companion nodes...\n");
	cn[0] = isactive(i, j, k, nlist) ? nlist[IJK] : NULL;
	cn[1] = isactive(i + 1, j, k, nlist) ? nlist[IJK + 1] : NULL;
	cn[2] = isactive(i + 1, j + 1, k, nlist) ? nlist[IJK + 1 + FS] : NULL;
	cn[3] = isactive(i, j + 1, k, nlist) ? nlist[IJK + FS] : NULL;
	cn[4] = isactive(i, j, k + 1, nlist) ? nlist[IJK + FSS] : NULL;
	cn[5] = isactive(i + 1, j, k + 1, nlist) ? nlist[IJK + 1 + FSS] : NULL;
	cn[6] = isactive(i + 1, j + 1, k + 1, nlist) ?
		nlist[IJK + 1 + FS + FSS] : NULL;
	cn[7] = isactive(i, j + 1, k + 1, nlist) ? nlist[IJK + FS + FSS] : NULL;
}

t_cube			*fdf_get_cube(int *i, t_cube *cb, t_node **nlist, t_node **cn)
{
	char	cube;
	int		fv[6];

	printf("getting cube in {%d}{%d}{%d}\n", i[0], i[1], i[2]);
	companion_nodes(i[0], i[1], i[2], nlist, cn);
	printf("got the companion_nodes\n");
	cube = companion_cube(cn);
	printf("got the companion_cube : %hhd\n", cube);
	cb = fdf_cube_is_a_lie(cb, cube, cn, fv);
	printf("understood the lie\n");
	return (cb);
}
