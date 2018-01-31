/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:19:47 by jquenel           #+#    #+#             */
/*   Updated: 2018/01/30 02:00:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>

static int	is_valid_tab(char *tab)
{
	int i;

	i = 0;
	if (tab[i] == '-')
	{
		if (!tab[i + 1] || !ft_isdigit(tab[i + 1]))
			return (0);
		i++;
	}
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]))
			return (0);
		i++;
	}
	return ((i < 10) && (ft_atol(tab) < INT_MAX) &&
			(ft_atol(tab) > INT_MIN) ? 1 : 0);
}

static t_bool			fdf_filechecker(t_tlist *tabs)
{
	int		w;
	int		i;

	w = 0;
	while (tabs && tabs->tab && tabs->tab[w++])
		;
	if (w == 0)
		return (FALSE);
	while (tabs->next)
		tabs = tabs->next;
	i = -1;
	while (tabs->tab[++i])
		if (!is_valid_tab(tabs->tab[i]))
				return (FALSE);
	if (i != w - 1)
		return (FALSE);
	return (TRUE);
}

void				fdf_get_nlist(t_env *env)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = MAP(node);
	i = fdf_nodecount(env);
	//checkerror
	ft_err(!(MAP(nlist) = malloc(sizeof(t_node *) * (i + 1))), ERR_M, 0);
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

	tabs = NULL;
	line = NULL;
	while ((i = get_next_line(fd, &line)) && i != -1)
	{
		fdf_tlstpushback(&tabs, fdf_tlstnew(ft_strsplit(line, ' ')));
		free(line);
		ft_err(!(fdf_filechecker(tabs)), ERR_MAP, 0);
	}
	MAP(w) = 0;
	while (tabs)
	{
		MAP(h) = -1;
		while ((tabs->tab)[++MAP(h)])
			fdf_addnode(&(env->map->node),
		fdf_newnode(ft_v3d_new(MAP(w), MAP(h), ft_atol((tabs->tab)[MAP(h)]))));
		tabs = tabs->next;
		MAP(w)++;
	}
	ft_err((MAP(w) == 0 && MAP(h) == 0), ERR_MAP, 0);
	fdf_facebuilder(env);
	CAM(pos.y) += MAX(MAP(w), MAP(h));
}

void				fdf_parser(t_env *env, char *arg)
{
	int		fd;

	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		env->map->type = 1;
		fdfractol(env);
	}
	else
	{
		env->map->type = 2;
		fdfer(env, fd);
	}
	printf("Finished parsing.\n");
}
