/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:19:47 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/27 21:46:48 by jquenel          ###   ########.fr       */
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

#define NA		(MAP(nlist)[i])
#define NB		(MAP(nlist)[i + 1])
#define	NC		(MAP(nlist)[i + MAP(h) + 1])
#define ND		(MAP(nlist)[i + MAP(h)])

static void			fdf_filechecker(t_tlist *tabs)
{
	//ft_errcheck
	(void)tabs;
	return ;
}

void				fdf_get_nlist(t_env *env)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = MAP(node);
	i = fdf_nodecount(env);
	//checkerror
	MAP(nlist) = malloc(sizeof(t_node *) * (i + 1));
	MAP(nlist)[i] = NULL;
	j = 0;
	while (j < i)
	{
		MAP(nlist)[j] = tmp;
		tmp = tmp->next;
		j++;
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
	printf("OK\n");
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
	printf("OK\n");
	printf("building faces...");
	while (NA && NB && ND && NC && i + MAP(h) < node_count)
	{
		if ((i + 1) % MAP(h))
		{
			if ((ABS(NA->v.z - NC->v.z)) > (ABS(NB->v.z - ND->v.z)))
			{
				fdf_addface(&MAP(face), fdf_newface(NA, NB, ND));
				fdf_addface(&MAP(face), fdf_newface(NB, NC, ND));
			//if (MAP(face))
			//	printf("added face\n");
			}
			else
			{
				fdf_addface(&MAP(face), fdf_newface(NA, NB, NC));
				fdf_addface(&MAP(face), fdf_newface(NA, NC, ND));
			//if (MAP(face))
			//	printf("added face\n");
			}
		}
		i++;
	}
	//read_face(env);
	printf("OK\n");
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
		j = -1;
		while ((tabs->tab)[++j])
			fdf_addnode(&(env->map->node), fdf_newnode(ft_v3d_new(i, j,
						ft_atoi((tabs->tab)[j]))));
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
	printf("Finished parsing.\n");
}
