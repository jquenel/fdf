/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_3_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 04:32:15 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 22:43:35 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

static void	rotate_3_2(t_cube *cb)
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

static void	case_1(t_cube *cb, t_node *n, t_env *env)
{
	printf("3_2_1\n");
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, n, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, n, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OC, n, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MB, n, OC, env));
}

static void	case_2(t_cube *cb, t_node *n, t_env *env)
{
	printf("3_2_2\n");
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, OD, n, env));
	fdf_addface(&MAP(face), fdf_newface(MA, n, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MB, n, env));
	fdf_addface(&MAP(face), fdf_newface(MD, n, OD, env));
}

void		wut_face_3_2(t_cube *cb, t_env *env)
{
	rotate_3_2(cb);
	if (OA)
		case_1(cb, OA, env);
	else if (OD)
	{
		if (OC)
			case_2(cb, OC, env);
		else
			case_2(cb, OB, env);
	}
	else
		case_1(cb, OB, env);
}
