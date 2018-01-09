/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loadmatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:19:23 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/09 17:16:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libmat.h"

void		fdf_sets(t_env *env)
{
	if (env->keymap & FM_NPLUS)
		CAM(speed) += 0.01;
	if (env->keymap & FM_NMINUS)
		CAM(speed) -= 0.01;
}

void		fdf_move(t_env *env)
{
	// can be changed to variable speed input. (e.g. CAM(angle.c) += xrot;)
	if (env->keymap & FM_UP)
		CAM(angle.x) += 0.01;
	else if (env->keymap & FM_DOWN)
		CAM(angle.x) -= 0.01;
	if (env->keymap & FM_N4)
		CAM(angle.y) += 0.01;
	else if (env->keymap & FM_N6)
		CAM(angle.y) -= 0.01;
	if (env->keymap & FM_LEFT)
		CAM(angle.z) -= 0.01;
	else if (env->keymap & FM_RIGHT)
		CAM(angle.z) += 0.01;
	if (env->keymap & FM_W)
		CAM(pos.y) -= CAM(speed);
	else if (env->keymap & FM_S)
		CAM(pos.y) += CAM(speed);
	if (env->keymap & FM_A)
		CAM(pos.x) += CAM(speed);
	else if (env->keymap & FM_D)
		CAM(pos.x) -= CAM(speed);
	fdf_sets(env);
}

int			fdf_applymatrices(t_env *env)
{
	//ici du multithread possible
	t_node		*n;

	fdf_loadmatrix(env);
	n = MAP(node);
	while (n)
	{
		n->dv = ft_v3d_new(n->v.x, n->v.y, n->v.z);
		n->dv = ft_v3d_x_mx4(n->dv, CAM(viewm));
		if (n->dv.y == 0)
			n->dv.y += 0.1;
		n = n->next;
	}
	if (CAM(mode))
		fdf_zsortfaces(env);
	n = MAP(node);
	while (n)
	{
	//find a way to put this into matrices
		//n->dv.x = n->dv.x * CAM(yratio) * 3+ WIDTH / 2;
		//n->dv.z = n->dv.z * CAM(yratio) * 3 + HEIGHT / 2;
		n->dv.x = n->dv.x * ZOOM * 30 / n->dv.y + WIDTH / 2;
		n->dv.z = n->dv.z * ZOOM * 35 / n->dv.y + HEIGHT / 2;
		n = n->next;
	}
	return (1);
}

static t_mx4	get_movement(t_env *env)
{
	t_mx4	move;

	move = ft_mx4_new(ft_v3d_new(1, 0, 0), ft_v3d_new(0, 1, 0),
			ft_v3d_new(0, 0, 1));
	if (env->keymap & FM_W)
		move.mat[1][3] = -CAM(speed);
	else if (env->keymap & FM_S)
		move.mat[1][3] = CAM(speed);
	if (env->keymap & FM_A)
		move.mat[0][3] = CAM(speed);
	else if (env->keymap & FM_D)
		move.mat[0][3] = -CAM(speed);
	return (move);
}

void		fdf_loadmatrix(t_env *env)
{
	t_mx4	amat;

	amat = get_movement(env);
	if (env->keymap & (FM_UP | FM_DOWN))
		amat = ft_mx4_x_mx4(xrot_mx4(env->keymap & FM_UP ? 0.02 : -0.02), amat);
	if (env->keymap & (FM_LEFT | FM_RIGHT))
		amat = ft_mx4_x_mx4(zrot_mx4(env->keymap & FM_LEFT ? -0.02 : 0.02), amat);
	if (env->keymap & (FM_N4 | FM_N6))
		amat = ft_mx4_x_mx4(yrot_mx4(env->keymap & FM_N6 ? 0.02 : -0.02), amat);
	CAM(viewm) = ft_mx4_x_mx4(amat, CAM(viewm));
}
