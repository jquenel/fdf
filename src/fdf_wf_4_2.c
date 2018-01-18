/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_4_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 02:59:18 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 03:41:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	build_4_2(t_cube *cb, t_node *n1, t_node *n2, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, n1, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, n1, n2, env)); 
	fdf_addface(&MAP(face), fdf_newface(MC, MB, n2, env)); 
	fdf_addface(&MAP(face), fdf_newface(MC, n2, MD, env)); 
	fdf_addface(&MAP(face), fdf_newface(MD, n2, n1, env)); 
	fdf_addface(&MAP(face), fdf_newface(MA, MD, n1, env)); 
}

void		wut_face_4_2(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MD, env));
	if (OA)
	{
		if (OB)
			build_4_2(cb, OA, OB, env);
		else if (OC)
			build_4_2(cb, OA, OC, env);
		else
			build_4_2(cb, OA, OD, env);
	}
	else if (OB)
	{
		if (OC)
			build_4_2(cb, OB, OC, env);
		else
			build_4_2(cb, OB, OD, env);
	}
	else
		build_4_2(cb, OD, OC, env);
}
