#include "fdf.h"
#include "libmat.h"

void		fdf_move(t_env *env)
{
	// can be changed to variable speed input. (e.g. CAM(angle.c) += xrot;)
	if (env->keymap & FM_UP)
		CAM(angle.x) -= 0.01;
	if (env->keymap & FM_DOWN)
		CAM(angle.x) += 0.01;
	if (env->keymap & FM_N4)
		CAM(angle.y) += 0.01;
	if (env->keymap & FM_N6)
		CAM(angle.y) -= 0.01;
	if (env->keymap & FM_LEFT)
		CAM(angle.z) += 0.01;
	if (env->keymap & FM_RIGHT)
		CAM(angle.z) -= 0.01;
	if (env->keymap & FM_W)
		CAM(pos.y) -= CAM(speed);
	if (env->keymap & FM_S)
		CAM(pos.y) += CAM(speed);
	if (env->keymap & FM_A)
		CAM(pos.x) -= CAM(speed);
	if (env->keymap & FM_D)
		CAM(pos.x) += CAM(speed);
}

int			fdf_applymatrices(t_v3d *v, t_env *env)
{
	*v = ft_v3d_x_mx4(*v, CAM(viewm));
	/**v = ft_v3d_add(*v, CAM(pos));
	*v = ft_v3d_x_mx4(*v, xrot_mx4(CAM(angle.x)));
	*v = ft_v3d_x_mx4(*v, yrot_mx4(CAM(angle.y)));
	*v = ft_v3d_x_mx4(*v, zrot_mx4(CAM(angle.z)));
	*/
	if (v->y > 100000 || v->y <= 0.1)
		return (0);
	if (v->y == 0)
		v->y++;
	v->x = v->x * ZOOM * ZOOM / v->y + WIDTH / 2;
	v->z = v->z * ZOOM * ZOOM / v->y + HEIGHT / 2;
	return (1);
}

t_mx4		fdf_loadmatrix(t_env *env)
{
	return (ft_mx4_x_mx4(ft_mx4_transl(CAM(pos)), ft_mx4_rot(CAM(angle))));
}
