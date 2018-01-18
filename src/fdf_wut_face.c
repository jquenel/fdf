/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wut_face.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:20:59 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 08:30:20 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MA		cb->main[0]
#define MB		cb->main[1]
#define MC		cb->main[2]
#define MD		cb->main[3]
#define OA		cb->opp[0]
#define OB		cb->opp[1]
#define OC		cb->opp[2]
#define OD		cb->opp[3]

void	fdf_wut_face(t_cube *cb, t_env *env)
{
	if (cb->m == 4)
	{
		if (cb->o == 4 || cb->o == 3)
			cb->o == 4 ? wut_face_4_4(cb, env) : wut_face_4_3(cb, env);
		else if (cb->o == 2 || cb->o == 1)
			cb->o == 2 ? wut_face_4_2(cb, env) : wut_face_4_1(cb, env);
		else
			wut_face_4_0(cb, env);
	}
	else if (cb->m == 3)
	{
		if (cb->o == 3)
			wut_face_3_3(cb, env);
		else if (cb->o == 2)
			wut_face_3_2(cb, env);
		else if (cb->o == 1)
			wut_face_3_1(cb, env);
		else
			wut_face_3_0(cb, env);
	}
	else
		wut_face_2_1(cb, env);
}
