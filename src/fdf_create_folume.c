#include "fdf.h"
#include <stdlib.h>

void	fdf_create_folume (t_env *env)
{
	int		i[3];
	t_node	**cn;

	i[0] = FAL_SIZE;
	ft_err(!(cn = (t_node **)malloc(sizeof(t_node *) * 8)), ERR_M, 0);
	while (i[0]-- && (i[1] = FAL_SIZE))
	{
		while (i[1]-- && (i[2] = FAL_SIZE))
		{
			while (i[2]--)
				fdf_wut_face(fdf_get_cube(i, FAL(nlist), cn),
				env);
		}
	}	
}
