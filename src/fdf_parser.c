/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:19:47 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/29 14:04:13 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

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

void				fdfer(t_env *env, int fd)
{
	t_tlist		*tabs;
	char		*line;
	int			i;

	//ft_errcheck
	tabs = NULL;
	while ((i = get_next_line(fd, &line)) && i != -1)
		fdf_tlstpushback(&tabs, fdf_tlstnew(ft_strsplit(line, ' ')));
	free(line);
	fdf_filechecker(tabs);
	MAP(w) = 0;
	while (tabs)
	{
		MAP(h) = -1;
		while ((tabs->tab)[++MAP(h)])
			fdf_addnode(&(env->map->node),
		fdf_newnode(ft_v3d_new(MAP(w), MAP(h), ft_atoi((tabs->tab)[MAP(h)]))));
		tabs = tabs->next;
		MAP(w)++;
	}
	fdf_facebuilder(env);
	CAM(pos.y) += MAX(MAP(w), MAP(h));
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
