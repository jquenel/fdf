/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_3_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:48:33 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 20:51:15 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	rotate_3_1(t_cube *cb)
{
	if (!MC)
		return ;
	else if (!MA)
	{
		fdf_cube_rotate_clock(cb);
		fdf_cube_rotate_clock(cb);
	}
	else if (!MB)
		fdf_cube_rotate_clock(cb);
	else
		fdf_cube_rotate_counter_clock(cb);
}

static void	wf31(t_cube *cb, t_node *n, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, n, env));
	fdf_addface(&MAP(face), fdf_newface(MA, n, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, n, MD, env));
}

void	wut_face_3_1(t_cube *cb, t_env *env)
{
	rotate_3_1(cb);
	if (OA)
		wf31(cb, OA, env);
	else if (OB)
		wf31(cb, OB, env);
	else if (OC)
		wf31(cb, OC, env);
	else
		wf31(cb, OD, env);
}
