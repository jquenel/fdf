/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mx4_x_mx4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:42:36 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/21 15:45:24 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat.h"

#define M1(x, y)		m1->mat[(x)][(y)]
#define M2(x, y)		m2.mat[(x)][(y)]

static void			mx4_mult(t_mx4 *m1, t_mx4 const m2, int col)
{
	M1(col, 0) = M1(col, 0) * M2(0 , 0) + M1(col, 1) * M2(1, 0) +
				M1(col, 2) * M2(2, 0) + M1(col, 3) * M2(3, 0);
	M1(col, 1) = M1(col, 0) * M2(0 , 1) + M1(col, 1) * M2(1, 1) +
				M1(col, 2) * M2(2, 1) + M1(col, 3) * M2(3, 1);
	M1(col, 2) = M1(col, 0) * M2(0 , 2) + M1(col, 1) * M2(1, 2) +
				M1(col, 2) * M2(2, 2) + M1(col, 3) * M2(3, 2);
	M1(col, 3) = M1(col, 0) * M2(0 , 3) + M1(col, 1) * M2(1, 3) +
				M1(col, 2) * M2(2, 3) + M1(col, 3) * M2(3, 3);
}

void				ft_mx4_x_mx4(t_mx4 *m1, t_mx4 const m2)
{
	mx4_mult(m1, m2, 0);
	mx4_mult(m1, m2, 1);
	mx4_mult(m1, m2, 2);
	mx4_mult(m1, m2, 3);
}
