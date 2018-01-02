/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotxyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:06:35 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/30 19:41:16 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx4		fdf_rot(t_v3d pos, double t, t_mx4 (*f)(double))
{
	t_v3d	dpos;

	dpos = ft_v3d_new(-pos.x, -pos.y, -pos.z);
	return (ft_mx4_x_mx4(
			ft_mx4_x_mx4(ft_mx4_change(pos), (*f)(t)),
			ft_mx4_change(dpos)));
}
