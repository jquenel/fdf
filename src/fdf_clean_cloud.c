/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean_cloud.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 22:57:40 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/31 20:06:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define IJK		i + j * FAL_SIZE + k * FAL_SIZE * FAL_SIZE

static int		is_lit(int i, int j, int k, t_env *env)
{
	if (i < 0 || j < 0 || k < 0 ||
		i >= FAL_SIZE || j >= FAL_SIZE || k >= FAL_SIZE)
		return (0);
	return (FAL(nlist)[IJK]->lit);
}

static int		unlit_storage(int i, int j, int k, t_env *env)
{
	FAL(nlist)[IJK]->active = 0;
	if (!(is_lit(i - 1, j - 1, k - 1, env) + is_lit(i - 1, j - 1, k, env) +
		is_lit(i - 1, j - 1, k + 1, env) + is_lit(i - 1, j, k - 1, env) +
		is_lit(i - 1, j + 1, k - 1, env) + is_lit(i - 1, j, k, env) +
		is_lit(i - 1, j, k + 1, env) + is_lit(i - 1, j + 1, k, env) +
		is_lit(i - 1, j + 1, k + 1, env) + is_lit(i, j - 1, k - 1, env) +
		is_lit(i, j - 1, k, env) + is_lit(i, j - 1, k + 1, env) +
		is_lit(i, j, k - 1, env) + is_lit(i, j + 1, k - 1, env) +
		is_lit(i, j + 1, k, env) + is_lit(i, j, k + 1, env) +
		is_lit(i + 1, j - 1, k - 1, env) + is_lit(i + 1, j - 1, k, env) +
		is_lit(i + 1, j - 1, k + 1, env) + is_lit(i + 1, j, k - 1, env) +
		is_lit(i + 1, j + 1, k - 1, env) + is_lit(i + 1, j, k, env) +
		is_lit(i + 1, j, k + 1, env) + is_lit(i + 1, j + 1, k, env) +
		is_lit(i + 1, j + 1, k + 1, env)))
		fdf_move_node(&FAL(npool), &MAP(node), FAL(nlist)[IJK]);
	return (0);
}

static int		activate(int i, int j, int k, t_env *env)
{
	if (!(FAL(nlist)[IJK]->lit))
		return (unlit_storage(i, j, k, env));
	else if (is_lit(i - 1, j - 1, k - 1, env) + is_lit(i - 1, j - 1, k, env) +
		is_lit(i - 1, j - 1, k + 1, env) + is_lit(i - 1, j, k - 1, env) +
		is_lit(i - 1, j + 1, k - 1, env) + is_lit(i - 1, j, k, env) +
		is_lit(i - 1, j, k + 1, env) + is_lit(i - 1, j + 1, k, env) +
		is_lit(i - 1, j + 1, k + 1, env) + is_lit(i, j - 1, k - 1, env) +
		is_lit(i, j - 1, k, env) + is_lit(i, j - 1, k + 1, env) +
		is_lit(i, j, k - 1, env) + is_lit(i, j + 1, k - 1, env) +
		is_lit(i, j + 1, k, env) + is_lit(i, j, k + 1, env) +
		is_lit(i + 1, j - 1, k - 1, env) + is_lit(i + 1, j - 1, k, env) +
		is_lit(i + 1, j - 1, k + 1, env) + is_lit(i + 1, j, k - 1, env) +
		is_lit(i + 1, j + 1, k - 1, env) + is_lit(i + 1, j, k, env) +
		is_lit(i + 1, j, k + 1, env) + is_lit(i + 1, j + 1, k, env) +
		is_lit(i + 1, j + 1, k + 1, env) == 26)
		return ((FAL(nlist)[IJK]->active = 0));
	else
		return ((FAL(nlist)[IJK]->active = 1));
}

void		fdf_clean_cloud(t_env *env)
{
	int			i[3];

	i[0] = FAL_SIZE;
	while (i[0]-- && (i[1] = FAL_SIZE))
	{
		while (i[1]-- && (i[2] = FAL_SIZE))
		{
			while (i[2]--)
			{
				//printf("{%d}{%d}{%d}\n", i[0], i[1], i[2]);
				activate(i[0], i[1], i[2], env);
			}
		}
	}
	//printf("cleaned\n");
}
