#include "fdf.h"

void	main_face_1(t_cube *cb, char cube, t_node **cn)
{
	int		i;

	i = 0;
	if (cube & 128)
		cb->main[i++] = cn[0];
}
