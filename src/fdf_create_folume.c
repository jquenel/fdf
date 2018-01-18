/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_create_folume.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 23:27:20 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/17 23:27:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	fdf_create_folume (t_env *env)
{
	int		i[3];
	t_node	**cn;
	t_cube	cb;

	ft_err(!(cn = (t_node **)malloc(sizeof(t_node *) * 8)), ERR_M, 0);
	i[0] = 8;
	while (i[0]--)
		ft_err(!(cn[i[0]] = (t_node *)malloc(sizeof(t_node))), ERR_M, 0);
	i[0] = FAL_SIZE;
	while (i[0]-- && (i[1] = FAL_SIZE))
	{
		while (i[1]-- && (i[2] = FAL_SIZE))
		{
			while (i[2]--)
				fdf_wut_face(fdf_get_cube(i, &cb, FAL(nlist), cn),
				env);
		}
	}
}
