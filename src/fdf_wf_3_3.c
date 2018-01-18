/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_3_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 03:42:53 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 03:58:49 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	case_no_MA(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MB, MC, MD, env));
	fdf_addface(&MAP(face), fdf_newface(OA, OD, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OB, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MB, MD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OD, OA, env));
}

static void	case_no_MB(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MC, MD, MA, env));
	fdf_addface(&MAP(face), fdf_newface(OB, OA, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OC, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MA, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OA, OB, env));
}

static void	case_no_MC(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MD, MA, MB, env));
	fdf_addface(&MAP(face), fdf_newface(OC, OB, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OD, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MB, MA, OB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OB, OC, env));
}

static void	case_no_MD(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(OD, OC, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MB, MA, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MC, OC, OD, env));
}

void	wut_face_3_3(t_cube *cb, t_env *env)
{
	if (!MA)
		case_no_MA(cb, env);
	else if (!MB)
		case_no_MB(cb, env);
	else if (!MC)
		case_no_MC(cb, env);
	else
		case_no_MD(cb, env);
}
