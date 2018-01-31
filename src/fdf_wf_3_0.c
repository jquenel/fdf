/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_wf_3_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:55:45 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/29 21:58:47 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

void	wut_face_3_0(t_cube *cb, t_env *env)
{
	if (!MA)
	{
		fdf_addface(&MAP(face), fdf_newface(MB, MC, MD, env));
		fdf_addface(&MAP(face), fdf_newface(MB, MD, MC, env));
	}
	else if (!MB)
	{
		fdf_addface(&MAP(face), fdf_newface(MC, MD, MA, env));
		fdf_addface(&MAP(face), fdf_newface(MC, MA, MD, env));
	}
	else if (!MC)
	{
		fdf_addface(&MAP(face), fdf_newface(MB, MD, MA, env));
		fdf_addface(&MAP(face), fdf_newface(MB, MA, MD, env));
	}
	else
	{
		fdf_addface(&MAP(face), fdf_newface(MC, MB, MA, env));
		fdf_addface(&MAP(face), fdf_newface(MC, MA, MB, env));
	}
}
