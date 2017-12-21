/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:11:49 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/21 16:25:23 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

void		ft_v3d_add(t_v3d *v1, t_v3d const v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}
