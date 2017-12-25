#include "libmat.h"
#include <math.h>

t_mx4	ft_mx4_transl(t_v3d pos)
{
	t_mx4	m;

	m.mat[0][0] = 0;
	m.mat[0][1] = 0;
	m.mat[0][2] = 0;
	m.mat[0][3] = 0;
	m.mat[1][0] = 0;
	m.mat[1][1] = 0;
	m.mat[1][2] = 0;
	m.mat[1][3] = 0;
	m.mat[2][0] = 0;
	m.mat[2][1] = 0;
	m.mat[2][2] = 0;
	m.mat[2][3] = 0;
	m.mat[3][0] = pos.x;
	m.mat[3][1] = pos.y;
	m.mat[3][2] = pos.z;
	m.mat[3][3] = 1;
	return (m);
}