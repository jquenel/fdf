/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_4_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 00:51:04 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 21:03:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

void	case_no_od(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MD, OC, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OA, MA, env));
	fdf_addface(&MAP(face), fdf_newface(OA, OC, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OA, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OB, OC, env));
}

void	case_no_oc(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MC, OB, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OD, MD, env));
	fdf_addface(&MAP(face), fdf_newface(OD, OB, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OA, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OD, OA, env));
}

void	case_no_ob(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MB, MA, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OC, MC, env));
	fdf_addface(&MAP(face), fdf_newface(OC, OA, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OD, OA, env));
}

void	case_no_oa(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, OD, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OB, MB, env));
	fdf_addface(&MAP(face), fdf_newface(OB, OD, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OB, OC, env));
}

void	wut_face_4_3(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MD, env));
	if (!cb->opp[0])
		case_no_oa(cb, env);
	else if (!cb->opp[1])
		case_no_ob(cb, env);
	else if (!cb->opp[2])
		case_no_oc(cb, env);
	else
		case_no_od(cb, env);
}
