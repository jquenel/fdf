#include "fdf.h"
#include "libmat.h"

t_mx4		fdf_loadmatrix(t_env *env)
{
	return (ft_mx4_rot(CAM(angle)));
}
