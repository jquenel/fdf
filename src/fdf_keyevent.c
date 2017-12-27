/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_keyevent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 15:29:45 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 19:40:32 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int			fdf_keypressed(int keycode, t_env *env)
{
	if (keycode == FK_ESC)
		exit(0);
	if (keycode == FK_UP)
		env->keymap |= FM_UP;
	if (keycode == FK_DOWN)
		env->keymap |= FM_DOWN;
	if (keycode == FK_RIGHT)
		env->keymap |= FM_RIGHT;
	if (keycode == FK_LEFT)
		env->keymap |= FM_LEFT;
	if (keycode == FK_RIGHT)
		env->keymap |= FM_RIGHT;
	if (keycode == FK_A)
		env->keymap |= FM_A;
	if (keycode == FK_D)
		env->keymap |= FM_D;
	return (0);
}

int			fdf_keyreleased(int keycode, t_env *env)
{
	if (keycode == FK_UP)
		env->keymap ^= (FM_UP & env->keymap);
	if (keycode == FK_DOWN)
		env->keymap ^= (FM_DOWN & env->keymap);
	if (keycode == FK_RIGHT)
		env->keymap ^= (FM_RIGHT & env->keymap);
	if (keycode == FK_LEFT)
		env->keymap ^= (FM_LEFT & env->keymap);
	if (keycode == FK_A)
		env->keymap ^= (FM_A & env->keymap);
	if (keycode == FK_D)
		env->keymap ^= (FM_D & env->keymap);
	return (0);
}
