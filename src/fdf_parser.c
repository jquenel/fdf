/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:19:47 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/22 12:49:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

/*
**		NA-----NB
**		|      |
**		|      |
**		|      |
**		ND-----NC
*/

#define NA		MAP(nlist)[i]
#define NB		MAP(nlist)[i + 1]
#define	NC		MAP(nlist)[i + MAP(w) + 1]
#define ND		MAP(nlist)[i + MAP(w)]

static void			fdf_filechecker(t_tlist *tabs)
{
	//ft_errcheck
	(void)tabs;
	return ;
}

void				fdf_get_nlist(t_env *env)
{
	int		i;
	t_node	*tmp;

	tmp = MAP(node);
	i = fdf_nodecount(env);
	//checkerror
	MAP(nlist) = malloc(sizeof(t_node *) * (i + 1));
	MAP(nlist)[i] = NULL;
	while (i--)
	{
		MAP(nlist)[i] = tmp;
		tmp = tmp->next;
	}
}

void				fdf_facebuilder(t_env *env)
{
	t_node	*tmp;
	int		i;
	int		node_count;

	tmp = env->map->node;
	printf("getting nlist...");
	fdf_get_nlist(env);
	while (tmp)
	{
		tmp->v.x -= env->map->w / 2;
		tmp->v.y -= env->map->h / 2;
		tmp->v.z /= ZOOM / 2;
		//zoom adjustment to fix//
		tmp = tmp->next;
	}
	i = 0;
	printf("getting nodecount...");
	node_count = fdf_nodecount(env);
	printf("building faces...");
	while (MAP(nlist)[i] && i + MAP(w) < node_count)
	{
		printf("
		if ((i + 1) % MAP(w))
		{
			if (ABS(NA->v.z - NC->v.z) < ABS(NB->v.z - ND->v.z))
			{
				fdf_addface(&MAP(face), fdf_newface(NA, NB, ND));
				fdf_addface(&MAP(face), fdf_newface(NB, NC, ND));
			}
			else
			{
				fdf_addface(&MAP(face), fdf_newface(NA, NB, NC));
				fdf_addface(&MAP(face), fdf_newface(NA, NC, ND));
			}
		}
		i++;
	}
}

void				fdfer(t_env *env, int fd)
{
	t_tlist		*tabs;
	char		*line;
	int			i;
	int			j;

	//ft_errcheck
	tabs = NULL;
	while ((i = get_next_line(fd, &line)) && i != -1)
		fdf_tlstpushback(&tabs, fdf_tlstnew(ft_strsplit(line, ' ')));
	free(line);
	fdf_filechecker(tabs);
	i = 0;
	j = 0;
	while (tabs)
	{
		j = 0;
		while ((tabs->tab)[j])
			fdf_addnode(&(env->map->node), ft_v3d_new(i, j,
						ft_atoi((tabs->tab)[j++])));
		tabs = tabs->next;
		i++;
	}
	env->map->w = i;
	env->map->h = j;
	printf("finished parsing the nodes, building faces...\n");
	fdf_facebuilder(env);
	printf("finished building faces...\n");
}

void				fdf_parser(t_env *env, char *arg)
{
	int		fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		env->map->type = 1;
		fdfractol(env, arg);
	}
	else
	{
		env->map->type = 2;
		fdfer(env, fd);
	}
}
