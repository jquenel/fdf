/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v3d_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 22:43:49 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/31 22:47:47 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

float		ft_v3d_dot(t_v3d const v1, t_v3d const v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
