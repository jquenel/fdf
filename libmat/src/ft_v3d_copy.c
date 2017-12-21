/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:13:45 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/21 16:15:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

t_v3d		ft_v3d_copy(t_v3d v)
{
	t_v3d	w;

	w.x = v.x;
	w.y = v.y;
	w.z = v.z;
	return (w);
}