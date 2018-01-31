/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_2_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:06:00 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 23:28:31 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void		build_2side(t_node *n1, t_node *n2, t_node *n3, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(n1, n2, n3, env));
	fdf_addface(&MAP(face), fdf_newface(n2, n1, n3, env));
}

static void		wfa22(t_cube *cb, t_env *env)
{
	if (OA)
	{
		fdf_addface(&MAP(face), fdf_newface(OA, MB, MD, env));
		fdf_addface(&MAP(face), fdf_newface(OA, MD, OC, env));
		fdf_addface(&MAP(face), fdf_newface(OA, OC, MB, env));
		fdf_addface(&MAP(face), fdf_newface(MD, MB, OC, env));
	}
	else
	{
		fdf_addface(&MAP(face), fdf_newface(OD, MA, MC, env));
		fdf_addface(&MAP(face), fdf_newface(OD, MC, OB, env));
		fdf_addface(&MAP(face), fdf_newface(OD, OB, MA, env));
		fdf_addface(&MAP(face), fdf_newface(MA, OB, MC, env));
	}
}


static void		wf22(t_cube *cb, t_node *n1, t_node *n2, t_env *env)
{
	if (OA)
	{
		build_2side(n1, n2, OA, env);
		if (OB)
			build_2side(n2, OA, OB, env);
		else
			build_2side(n2, OA, OC ? OC : OD, env);
	}
	else if (OB)
	{
		build_2side(n1, n2, OB, env);
		build_2side(n2, OB, OC ? OC : OD, env);
	}
	else
	{
		build_2side(n1, n2, OC, env);
		build_2side(n1, OC, OD, env);
	}
}

void			wut_face_2_2(t_cube *cb, t_env *env)
{
	if (MA)
	{
		if (MB)
			wf22(cb, MA, MB, env);
		else if (MC)
			OA && OC ? wf22(cb, MA, MC, env) : wfa22(cb, env);
		else
			wf22(cb, MA, MD, env);
	}
	else if (MB)
	{
		if (MC)
			wf22(cb, MB, MC, env);
		else
			OB && OD ? wf22(cb, MB, MD, env) : wfa22(cb, env);
	}
	else
		wf22(cb, MC, MD, env);
}
