/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wut_face.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:20:59 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 23:15:38 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_wut_face(t_cube *cb, t_env *env)
{
	if (!cb)
		return ;
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
		cb->o == 2 ? wut_face_2_2(cb, env) : wut_face_2_1(cb, env);
}
