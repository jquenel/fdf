/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cube_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 19:39:32 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 22:40:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdfcube.h"

void	fdf_cube_rotate_clock(t_cube *cb)
{
	t_node	*tmp;

	tmp = MA;
	MA = MD;
	MD = MC;
	MC = MB;
	MB = tmp;
	tmp = OA;
	OA = OD;
	OD = OC;
	OC = OB;
	OB = tmp;
}

void	fdf_cube_rotate_counter_clock(t_cube *cb)
{
	t_node	*tmp;

	tmp = MA;
	MA = MB;
	MB = MC;
	MC = MD;
	MD = tmp;
	tmp = OA;
	OA = OB;
	OB = OC;
	OC = OD;
	OD = tmp;
}


