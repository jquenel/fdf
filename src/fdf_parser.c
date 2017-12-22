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

static void			fdf_filechecker(t_tlist *tabs)
{
	//ft_errcheck
	(void)tabs;
	return ;
}

void				fdfer(t_env *env, int fd)
{
	t_tlist		*tabs;
	char		*line;
	int			i;
	int			j;

	//ft_errcheck
	printf("030\n");
	tabs = NULL;
	while ((i = get_next_line(fd, &line)) && i != -1)
		fdf_tlstpushback(&tabs, fdf_tlstnew(ft_strsplit(line, ' ')));
	printf("031\n");
	free(line);
	//ft_errcheck
	printf("032\n");
	fdf_filechecker(tabs);
	printf("033\n");
	i = 0;
	while (tabs)
	{
		j = 0;
		while ((tabs->tab)[j])
		{
	printf("035\n");
			fdf_addnode(&(env->map->node), ft_v3d_new(i, j,
						ft_atoi((tabs->tab)[j])));
			j++;
		}
	printf("034\n");
		tabs = tabs->next;
		i++;
	}
	printf("%lf\n", env->map->node->v.x);
	printf("036\n");
	env->map->w = i;
	printf("037\n");
	env->map->h = j;
}

void				fdf_parser(t_env *env, char *arg)
{
	int		fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		printf("00\n");
		env->map->type = 1;
		printf("01\n");
		fdfractol(env, arg);
	}
	else
	{
		printf("02\n");
		env->map->type = 2;
		printf("03\n");
		fdfer(env, fd);
	}
}
