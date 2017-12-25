#include "libmat.h"
#include <math.h>

t_mx4	xrot_mx4(double r)
{
	t_mx4	m;

	m.mat[0][0] = 1;
	m.mat[0][1] = 0;
	m.mat[0][2] = 0;
	m.mat[0][3] = 0;
	m.mat[1][0] = 0;
	m.mat[1][1] = cos(r);
	m.mat[1][2] = sin(r) * -1;
	m.mat[1][3] = 0;
	m.mat[2][0] = 0;
	m.mat[2][1] = sin(r);
	m.mat[2][2] = cos(r);
	m.mat[2][3] = 0;
	m.mat[3][0] = 0;
	m.mat[3][1] = 0;
	m.mat[3][2] = 0;
	m.mat[3][3] = 1;
	return (m);
}

t_mx4	yrot_mx4(double r)
{
	t_mx4	m;

	m.mat[0][0] = cos(r);
	m.mat[0][1] = 0;
	m.mat[0][2] = sin(r);
	m.mat[0][3] = 0;

	m.mat[1][0] = 0;
	m.mat[1][1] = 1;
	m.mat[1][2] = 0;
	m.mat[1][3] = 0;

	m.mat[2][0] = sin(r) * -1;
	m.mat[2][1] = 0;
	m.mat[2][2] = cos(r);
	m.mat[2][3] = 0;

	m.mat[3][0] = 0;
	m.mat[3][1] = 0;
	m.mat[3][2] = 0;
	m.mat[3][3] = 1;
	return (m);
}

t_mx4	zrot_mx4(double r)
{
	t_mx4	m;

	m.mat[0][0] = cos(r);
	m.mat[0][1] = sin(r) * -1;
	m.mat[0][2] = 0;
	m.mat[0][3] = 0;
	m.mat[1][0] = sin(r);
	m.mat[1][1] = cos(r);
	m.mat[1][2] = 0;
	m.mat[1][3] = 0;
	m.mat[2][0] = 0;
	m.mat[2][1] = 0;
	m.mat[2][2] = 1;
	m.mat[2][3] = 0;
	m.mat[3][0] = 0;
	m.mat[3][1] = 0;
	m.mat[3][2] = 0;
	m.mat[3][3] = 1;
	return (m);
}

t_mx4			ft_mx4_rot(t_v3d angle)
{
	return (ft_mx4_x_mx4(
	ft_mx4_x_mx4(xrot_mx4(angle.x), yrot_mx4(angle.y)),
	zrot_mx4(angle.z)));
	//return (zrot_mx4(angle.z));
}
