/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_4_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:49:09 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 03:42:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

void	wut_face_4_4(t_cube *cb, t_env *env)
{
	//face ABCD
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MD, env));
	//face ABB'A'
	fdf_addface(&MAP(face), fdf_newface(MA, OA, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OA, OB, env));
	//face ADD'A'
	fdf_addface(&MAP(face), fdf_newface(MA, MD, OA, env));
	fdf_addface(&MAP(face), fdf_newface(MD, OA, OD, env));
	//face DCC'D'
	fdf_addface(&MAP(face), fdf_newface(MD, OC, OD, env));
	fdf_addface(&MAP(face), fdf_newface(MD, MC, OC, env));
	//face CBB'C'
	fdf_addface(&MAP(face), fdf_newface(MC, MB, OC, env));
	fdf_addface(&MAP(face), fdf_newface(MB, OB, OC, env));
	//face A'B'C'D'
	fdf_addface(&MAP(face), fdf_newface(OA, OC, OB, env));
	fdf_addface(&MAP(face), fdf_newface(OA, OD, OC, env));
}
