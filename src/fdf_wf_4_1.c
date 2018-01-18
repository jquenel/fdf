/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_4_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 03:32:00 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 03:42:27 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	build_4_1(t_cube *cb, t_node *n1, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, n1, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, n1, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MC, n1, MD, env));
	fdf_addface(&MAP(face), fdf_newface(MD, n1, MA, env));
}

void		wut_face_4_1(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MD, env));
	if (OA)
		build_4_1(cb, OA, env);
	else if (OB)
		build_4_1(cb, OB, env);
	else if (OC)
		build_4_1(cb, OC, env);
	else
		build_4_1(cb, OD, env);
}
