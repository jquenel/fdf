/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fildefractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 20:02:41 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/11 21:45:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		fdf_fildefractol(t_finfos *cloud, t_env *env)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = FAL_SIZE;
	ft_err(!(FAL(vox) = malloc(sizeof(t_node) *
					FAL_SIZE * FAL_SIZE * FAL_SIZE)), ERR_M, 0);
	while (i-- && (j = FAL_SIZE))
	{
		while (j-- && (k = FAL_SIZE))
		{
			while (k--)
			{
				l = i + j * FAL_SIZE + k * FAL_SIZE * FAL_SIZE;
				FAL(vox)[l].lit = TRUE;
				if (cloud[l].lit)
				{
					FAL(vox)[l].fvalue = cloud[l].value;
					FAL(vox)[l].v = ft_v3d_new(i, j, k);
				}
			}
		}
	}
}
