/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_disco.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 02:27:26 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:18:22 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>

static char	*init_disco(void)
{
	char	*discoball;

	discoball = ft_strdup("[`)kegj[\\)g_(&#)x1e^^i!\
	[][)g+`.j^^\\x1e^^!_[i![])b^^i![][\
	`(j&\\#_)//.^![][)g(.g$e_(i\
	`!j/\\._g$/.^i!x1e^^i![][)g([]e_i!&+,\
	`(j&\\#_)//.^i![][)g(.g$e_(i\
	)`gj(\\&_#)/g+.^^![)x1e^^i![][.g\
	`[j)\\g_(&#.^^i![][)/x1e^^![][)g(g\
	`[]j[\\)_g+^^.^^![i![])x1e^^i![][\
	`(j&\\#_)//.^i![][)g(.g$e_(i\
	`!j/\\._g$/.^i!x1e^^i[][)g([]e_i!&+,\
	`(j&\\#_)//.^^i![][)g(.g$e_(i\
	`(j&\\#_)//.^^i![][)g(.g$e_(i\
	`!j&\\/_.g$e_(!&.^^i![][)g(+,\
	`[j)\\g_(&#^^i![][)/.^^i[][)g(g\
	`(j&\\#_)/.^^i![][)g(.g$e_(i\
	`(j&\\#_)//.^i![][)g(.g$e_(i\
	`!j/.\\g$_/.^i^^i![][)g(]_i!&+,\
	`/j.\\^^_i![[)g(&#)/.g_(i!&");
	return (discoball);
}

static void	dance(char color, char dancer)
{
	char	*show;
	char	*light;

	show = ft_strdup("\e[  m ");
	light = ft_itoa((int)color);
	show[2] = light[0];
	show[3] = light[1];
	show[5] = dancer;
	write(1, show, 6);
}

int			pf_disco_time(char *expr, int count)
{
	char	*dancers;
	char	*discoball;
	char	*dancefloor;
	int		hours;

	hours = 0;
	discoball = init_disco();
	while (hours++ < 1)
	{
		dancers = expr;
		while (*dancers)
		{
			dancefloor = discoball;
			dancefloor += count % 12;
			while (*dancefloor && *dancers)
			{
				dance(*(dancefloor++), *(dancers++));
				dance(0, *(dancers++));
			}
		}
	}
	return (count);
}
