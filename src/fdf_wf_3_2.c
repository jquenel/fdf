/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_3_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 04:32:15 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 08:30:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	set_main(t_cube *cb)
{
	if (!MA)
	{
		MA = MB;
		MB = MC;
		MC = MD;
	}
	else if (!MB)
	{
		MB = MC;
		MC = MD;
	}
	else if (!MC)
		MC = MD;
}

static void	build_3_2(t_cube *cb, t_node *n1, t_node *n2, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, n1, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, n1, env));

}

void		wut_face_3_2(t_cube *cb, t_env *env)
{
	set_main(cb);
	if (OA)
	{
		if (OB)
			build_3_2(cb, OA, OB, env);
		else if (OC)
			build_3_2(cb, OA, OC, env);
		else
			build_3_2(cb, OA, OD, env);
	}
	else if (OB)
	{
		if (OC)
			build_3_2(cb, OB, OC, env);
		else
			build_3_2(cb, OB, OD, env);
	}
	else
		build_3_2(cb, OC, OD, env);
}
