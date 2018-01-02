/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyevent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:29:45 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/31 14:45:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int			fdf_keypressed2(int keycode, t_env *env)
{
	if (keycode == FK_NPLUS)
		return (env->keymap |= FM_NPLUS);
	if (keycode == FK_NMINUS)
		return (env->keymap |= FM_NMINUS);
	if (keycode == FK_T)
		return (CAM(mode) = CAM(mode) ? 0 : 1);
	if (keycode == FK_ESC)
		exit(0);
	return (0);
}

int			fdf_keypressed(int keycode, t_env *env)
{
	if (keycode == FK_UP || keycode == FK_N5)
		return (env->keymap |= FM_UP);
	if (keycode == FK_DOWN || keycode == FK_N2)
		return (env->keymap |= FM_DOWN);
	if (keycode == FK_RIGHT || keycode == FK_N3)
		return (env->keymap |= FM_RIGHT);
	if (keycode == FK_LEFT || keycode == FK_N1)
		return (env->keymap |= FM_LEFT);
	if (keycode == FK_W)
		return (env->keymap |= FM_W);
	if (keycode == FK_A)
		return (env->keymap |= FM_A);
	if (keycode == FK_S)
		return (env->keymap |= FM_S);
	if (keycode == FK_D)
		return (env->keymap |= FM_D);
	if (keycode == FK_N4)
		return (env->keymap |= FM_N4);
	if (keycode == FK_N6)
		return (env->keymap |= FM_N6);
	return (fdf_keypressed2(keycode, env));
}


int			fdf_keyreleased2(int keycode, t_env *env)
{
	if (keycode == FK_NPLUS)
		return (env->keymap ^= (FM_NPLUS & env->keymap));
	if (keycode == FK_NMINUS)
		return (env->keymap ^= (FM_NMINUS & env->keymap));
	return (0);
}

int			fdf_keyreleased(int keycode, t_env *env)
{
	if (keycode == FK_UP || keycode == FK_N5)
		return (env->keymap ^= (FM_UP & env->keymap));
	if (keycode == FK_DOWN || keycode == FK_N2)
		return (env->keymap ^= (FM_DOWN & env->keymap));
	if (keycode == FK_RIGHT || keycode == FK_N3)
		return (env->keymap ^= (FM_RIGHT & env->keymap));
	if (keycode == FK_LEFT || keycode == FK_N1)
		return (env->keymap ^= (FM_LEFT & env->keymap));
	if (keycode == FK_N4)
		return (env->keymap ^= (FM_N4 & env->keymap));
	if (keycode == FK_N6)
		return (env->keymap ^= (FM_N6 & env->keymap));
	if (keycode == FK_W)
		return (env->keymap ^= (FM_W & env->keymap));
	if (keycode == FK_A)
		return (env->keymap ^= (FM_A & env->keymap));
	if (keycode == FK_S)
		return (env->keymap ^= (FM_S & env->keymap));
	if (keycode == FK_D)
		return (env->keymap ^= (FM_D & env->keymap));
	return (fdf_keyreleased2(keycode, env));
}
