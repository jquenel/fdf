/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_folume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:27:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 20:17:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	clean_cn(t_node ***cn)
{
	int		i;

	i = 8;
	while (i--)
		free((*cn)[i]);
	free(*cn);
	*cn = NULL;
}

void		fdf_create_folume (t_env *env)
{
	int		i[3];
	t_node	**cn;
	t_cube	*cb;

	ft_err(!(cn = (t_node **)malloc(sizeof(t_node *) * 8)), ERR_M, 0);
	ft_err(!(cb = (t_cube *)malloc(sizeof(t_cube))), ERR_M, 0);
	i[0] = 8;
	while (i[0]--)
		ft_err(!(cn[i[0]] = (t_node *)malloc(sizeof(t_node))), ERR_M, 0);
	printf("malloced cn. Ready tu wutface\n");
	i[0] = FAL_SIZE;
	while (i[0]-- && (i[1] = FAL_SIZE))
	{
		while (i[1]-- && (i[2] = FAL_SIZE))
		{
			while (i[2]--)
			{
				printf("attempting wutface {%d}{%d}{%d}\n", i[0], i[1], i[2]);
				if (i[0] < FAL_SIZE - 1 &&
					i[1] < FAL_SIZE - 1 &&
					i[2] < FAL_SIZE - 1)
				fdf_wut_face(fdf_get_cube(i, cb, FAL(nlist), cn), env);
			}
		}
	}
	printf("\n\n\n`finished wutfacing\n");
	//clean_cn(&cn);
}
