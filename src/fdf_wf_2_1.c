/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_2_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:59:21 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 19:44:10 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	wf21(t_cube *cb, t_node *n1, t_node *n2, t_env *env)
{
	if (OA)
	{
		fdf_addface(&MAP(face), fdf_newface(n1, n2, OA, env));
		fdf_addface(&MAP(face), fdf_newface(n2, n1, OA, env));
	}
	else if (OB)
	{
		fdf_addface(&MAP(face), fdf_newface(n1, n2, OB, env));
		fdf_addface(&MAP(face), fdf_newface(n2, n1, OB, env));
	}
	else if (OC)
	{
		fdf_addface(&MAP(face), fdf_newface(n1, n2, OC, env));
		fdf_addface(&MAP(face), fdf_newface(n2, n1, OC, env));
	}
	else
	{
		fdf_addface(&MAP(face), fdf_newface(n1, n2, OD, env));
		fdf_addface(&MAP(face), fdf_newface(n2, n1, OD, env));
	}
}

void	wut_face_2_1(t_cube *cb, t_env *env)
{
	if (MA)
	{
		if (MB)
			wf21(cb, MA, MB, env);
		else if (MC)
			wf21(cb, MA, MC, env);
		else
			wf21(cb, MA, MD, env);
	}
	else if (MB)
	{
		if (MC)
			wf21(cb, MB, MC, env);
		else
			wf21(cb, MB, MD, env);
	}
	else
		wf21(cb, MC, MD, env);
}
