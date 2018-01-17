#include "fdf.h"

void	main_face_1(t_cube *cb, char cube, t_node **cn, int *fv)
{
	int		i;

	cb->m = fv[1];
	cb->o = fv[3];
	i = 0;
	if (cube & 128)
		cb->main[i++] = cn[0];
	if (cube & 8)
		cb->main[i++] = cn[4];
	if (cube & 4)
		cb->main[i++] = cn[5];
	if (cube & 64)
		cb->main[i++] = cn[1];
	i = 0;
}
