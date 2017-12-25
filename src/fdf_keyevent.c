#include "fdf.h"
#include <stdlib.h>

int			fdf_keyevent(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit(0);
	if (keycode == XK_Up)
		CAM(angle.x) += 0.01;
	if (keycode == XK_Down)
		CAM(angle.x) -= 0.01;
	if (keycode == XK_Right)
		CAM(angle.z) += 0.01;
	if (keycode == XK_Left)
		CAM(angle.z) -= 0.01;
}
