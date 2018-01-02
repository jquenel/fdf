/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:13:40 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/31 22:48:17 by jquenel          ###   ########.fr       */
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
t_v3d				ft_v3d_add(t_v3d const v1, t_v3d const v2);
t_v3d				ft_v3d_sub(t_v3d const v1, t_v3d const v2);
float				ft_v3d_dot(t_v3d const v1, t_v3d const v2);
t_v3d				ft_v3d_normalize(t_v3d const v);
double				ft_v3d_dir(t_v3d const v);
double				ft_v3d_mag(t_v3d const v);
void				ft_v3d_copy(t_v3d *vd, t_v3d vs);

t_v3d				ft_v3d_x_v3d(t_v3d const v1, t_v3d const v2);
t_v3d				ft_v3d_x_mx4(t_v3d const v, t_mx4 const m);
t_mx4				ft_mx4_x_mx4(t_mx4 m1, t_mx4 m2);
t_mx4				ft_mx4_rot(t_v3d angle);
t_mx4				xrot_mx4(double r);
t_mx4				yrot_mx4(double r);
t_mx4				zrot_mx4(double r);
t_mx4				ft_mx4_transl(t_v3d v);
t_mx4				ft_mx4_change(t_v3d v);

#endif
