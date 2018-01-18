/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cube_is_a_lie.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:27:10 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/17 23:29:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	main_face_0(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[0];
	cb->o = fv[2];
	cb->main[0] = cube & 128 ? cn[0] : NULL;
	cb->main[1] = cube & 64 ? cn[1] : NULL;
	cb->main[2] = cube & 32 ? cn[2] : NULL;
	cb->main[3] = cube & 16 ? cn[3] : NULL;
	cb->opp[0] = cube & 8 ? cn[4] : NULL;
	cb->opp[1] = cube & 4 ? cn[5] : NULL;
	cb->opp[2] = cube & 2 ? cn[6] : NULL;
	cb->opp[3] = cube & 1 ? cn[7] : NULL;
	cb->cube = cube;
}

static int		get_fv(char cube, int *fv)
{
	ft_bzero(fv, sizeof(int) * 6);
	if (cube & 128)
		(void)(fv[0]++ / fv[1]++ / fv[4]++);
	if (cube & 64)
		(void)(fv[0]++ / fv[1]++ / fv[5]++);
	if (cube & 32)
		(void)(fv[0]++ / fv[3]++ / fv[5]++);
	if (cube & 16)
		(void)(fv[0]++ / fv[3]++ / fv[4]++);
	if (cube & 8)
		(void)(fv[1]++ / fv[2]++ / fv[4]++);
	if (cube & 4)
		(void)(fv[1]++ / fv[2]++ / fv[5]++);
	if (cube & 2)
		(void)(fv[2]++ / fv[3]++ / fv[5]++);
	if (cube & 1)
		(void)(fv[2]++ / fv[3]++ / fv[4]++);
	return (fv[0] + fv[1] + fv[2] + fv[3] + fv[4] + fv[5] - 3 < 0 ? 0 : 1);
}

void		fdf_cube_is_a_lie(t_cube *cb, char cube, t_node **cn, int *fv)
{
	if (!(get_fv(cube, fv)))
		return ;
	if (fv[0] >= fv[1] && fv[0] >= fv[2] && fv[0] >= fv[3] &&
		fv[0] >= fv[4] && fv[0] >= fv[5])
		main_face_0(cb, cube, cn, fv);
	else if (fv[1] >= fv[2] && fv[1] >= fv[3] &&
		fv[1] >= fv[4] && fv[1] >= fv[5])
		main_face_1(cb, cube, cn, fv);
	else if (fv[2] >= fv[3] && fv[2] >= fv[4] && fv[2] >= fv[5])
		main_face_2(cb, cube, cn, fv);
	else if (fv[3] >= fv[4] && fv[3] >= fv[5])
		main_face_3(cb, cube, cn, fv);
	else if (fv[4] >= fv[5])
		main_face_4(cb, cube, cn, fv);
	else
		main_face_5(cb, cube, cn, fv);
}
