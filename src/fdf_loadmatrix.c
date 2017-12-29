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
	if (env->keymap & FM_DOWN)
		CAM(angle.x) -= 0.01;
	if (env->keymap & FM_N4)
		CAM(angle.y) += 0.01;
	if (env->keymap & FM_N6)
		CAM(angle.y) -= 0.01;
	if (env->keymap & FM_LEFT)
		CAM(angle.z) -= 0.01;
	if (env->keymap & FM_RIGHT)
		CAM(angle.z) += 0.01;
	if (env->keymap & FM_W)
		CAM(pos.y) -= CAM(speed);
	if (env->keymap & FM_S)
		CAM(pos.y) += CAM(speed);
	if (env->keymap & FM_A)
		CAM(pos.x) += CAM(speed);
	if (env->keymap & FM_D)
		CAM(pos.x) -= CAM(speed);
	fdf_sets(env);
}

int			fdf_applymatrices(t_v3d *v, t_env *env)
{
	*v = ft_v3d_x_mx4(*v, CAM(viewm));
	if (v->y > 40 + CAM(pos.y) || v->y <= 0.1)
		return (0);
	if (v->y == 0)
		return (0);
	//find a way to put this into matrices
	v->x = v->x * CAM(yratio) * CAM(yratio) / v->y + WIDTH / 2;
	v->z = v->z * CAM(yratio) * CAM(yratio) / v->y + HEIGHT / 2;
	return (1);
}

t_mx4		fdf_loadmatrix(t_env *env)
{
	return (ft_mx4_x_mx4(ft_mx4_transl(CAM(pos)), ft_mx4_rot(CAM(angle))));
}
