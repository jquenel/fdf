#include "fdf.h"
#include <stdlib.h>

static int		*get_fv(char cube)
{
	int		*fv;

	ft_err(!(fv = (int *)malloc(sizeof(int) * 6)), ERR_M, 0);
	ft_bzero(fv, sizeof(int) * 6);
	if (cube & 128)
		fv[0]++ / fv[1]++ / fv[4]++;
	if (cube & 64)
		fv[0]++ / fv[1]++ / fv[5]++;
	if (cube & 32)
		fv[0]++ / fv[3]++ / fv[5]++;
	if (cube & 16)
		fv[0]++ / fv[3]++ / fv[4]++;
	if (cube & 8)
		fv[1]++ / fv[2]++ / fv[4]++;
	if (cube & 4)
		fv[1]++ / fv[2]++ / fv[5]++;
	if (cube & 2)
		fv[2]++ / fv[3]++ / fv[5]++;
	if (cube & 1)
		fv[2]++ / fv[3]++ / fv[4]++;
	return (fv[0] + fv[1] + fv[2] + fv[3] + fv[4] + fv[5] - 3 < 0 ? NULL : fv);
}

void		fdf_cube_is_a_lie(t_cube *cb, char cube, t_node **cn)
{
	int		*fv;

	if (!(fv = get_fv(cube)))
		return ;
	ft_err(!(cb = (t_cube *)malloc(sizeof(t_cube))), ERR_M, 0);
	if (fv[0] >= fv[1] && fv[0] >= fv[2] && fv[0] >= fv[3] &&
		fv[0] >= fv[4] && fv[0] >= fv[5])
		main_face_0(cb, cube, cn);
	else if (fv[1] >= fv[2] && fv[1] >= fv[3] &&
		fv[1] >= fv[4] && fv[1] >= fv[5])
		main_face_1(cb, cube, cn);
	else if (fv[2] >= fv[3] && fv[2] >= fv[4] && fv[2] >= fv[5])
		main_face_2(cb, cube, cn);
	else if (fv[3] >= fv[4] && fv[3] >= fv[5])
		main_face_3(cb, cube, cn);
	else if (fv[4] >= fv[5])
		main_face_4(cb, cube, cn);
	else
		main_face_5(cb, cube, cn);
}
