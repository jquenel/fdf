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

int			fdf_applymatrices(t_env *env)
{
	//ici du multithread possible
	t_node		*n;
	n = MAP(node);
	while (n)
	{
		n->dv = ft_v3d_new(n->v.x, n->v.y, n->v.z);
		n->dv = ft_v3d_x_mx4(n->dv, CAM(viewm));
		if (n->dv.y == 0)
			n->dv.y += 0.1;
		n = n->next;
	}
	//if (CAM(mode))
	//	fdf_zsortfaces(env);
	n = MAP(node);
	while (n)
	{
	//find a way to put this into matrices
		//n->dv.x = n->dv.x * CAM(yratio) * 3+ WIDTH / 2;
		//n->dv.z = n->dv.z * CAM(yratio) * 3 + HEIGHT / 2;
		n->dv.x = n->dv.x * CAM(yratio) * CAM(yratio) / n->dv.y + WIDTH / 2;
		n->dv.z = n->dv.z * CAM(yratio) * CAM(yratio) / n->dv.y + HEIGHT / 2;
		n = n->next;
	}
	return (1);
}

t_mx4		fdf_loadmatrix(t_env *env)
{
	return (ft_mx4_x_mx4(ft_mx4_change(CAM(pos)), ft_mx4_rot(CAM(angle))));
}
