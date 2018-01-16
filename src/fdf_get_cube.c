#include "fdf.h"
#include <stdlib.h>

static char		companion_cube(int i, int j, int k, t_node **cn)
{
	char	cube;

	cube = cn[0]->active * 128 +
			cn[1]->active * 64 +
			cn[2]->active * 32 +
			cn[3]->active * 16 +
			cn[4]->active * 8 +
			cn[5]->active * 4 +
			cn[6]->active * 2 +
			cn[7]->active;
	return (cube);
}

void			companion_nodes(int i, int j, int k, t_node ***nlist, t_node **cn)
{
	cn[0] = nlist[i][j][k].active ? &nlist[i][j][k] : NULL;
	cn[1] = nlist[i + 1][j][k].active ? &nlist[i + 1][j][k] : NULL;
	cn[2] = nlist[i + 1][j + 1][k].active ? &nlist[i + 1][j + 1][k] : NULL;
	cn[3] = nlist[i][j + 1][k].active ? &nlist[i][j + 1][k] : NULL;
	cn[4] = nlist[i][j][k + 1].active ? &nlist[i][j][k + 1] : NULL;
	cn[5] = nlist[i + 1][j][k + 1].active ? &nlist[i + 1][j][k + 1] : NULL;
	cn[6] = nlist[i + 1][j + 1][k + 1].active ?
	&nlist[i + 1][j + 1][k + 1] : NULL;
	cn[7] = nlist[i][j + 1][k + 1].active ? &nlist[i][j + 1][k + 1] : NULL;
}

t_cube	*fdf_get_cube(int i, int j, int k, t_node ***nlist, t_node **cn)
{
	t_cube	*cb;
	char	cube;

	cb = NULL;
	companion_nodes(i, j, k, nlist, cn);
	cube = companion_cube(i, j, k, cn);
	fdf_cube_is_a_lie(cb, cube, cn);
}
