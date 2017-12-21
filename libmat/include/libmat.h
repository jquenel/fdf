/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:13:40 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/21 16:16:07 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAT_H
# define LIBMAT_H

typedef struct		s_v3d
{
	double	x;
	double	y;
	double	z;
}					t_v3d;

typedef struct		s_mx4
{
	double	mat[4][4];
}					t_mx4;

t_v3d				ft_v3d_new(double x, double y, double z);
void				ft_v3d_add(t_v3d *v1, t_v3d const v2);
void				ft_v3d_sub(t_v3d *v1, t_v3d const v2);
void				ft_v3d_norm(t_v3d *v);
double				ft_v3d_dir(t_v3d const v);
double				ft_v3d_mag(t_v3d const v);
t_v3d				ft_v3d_copy(t_v3d v);

void				ft_v3d_x_mx4(t_v3d *v, t_mx4 const m);
void				ft_mx4_x_mx4(t_mx4 *m1, t_mx4 const m2);

#endif
