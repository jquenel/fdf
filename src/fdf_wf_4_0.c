/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_4_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 03:35:34 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/18 03:42:15 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

void		wut_face_4_0(t_cube *cb, t_env *env)
{
	fdf_addface(&MAP(face), fdf_newface(MA, MB, MC, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MD, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MC, MB, env));
	fdf_addface(&MAP(face), fdf_newface(MA, MD, MC, env));
}
