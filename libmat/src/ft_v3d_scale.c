/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:59:57 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/09 15:01:14 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_v3d		ft_v3d_scale(t_v3d v, float f)
{
	v.x *= f;
	v.y *= f;
	v.z *= f;
	return (v);
}
