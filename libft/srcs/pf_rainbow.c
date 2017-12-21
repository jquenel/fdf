/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:00:39 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:19:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	put_char(char *color, char c)
{
	char	*tmp;

	tmp = ft_strdup(color);
	tmp[5] = c;
	write(1, tmp, 6);
	free(tmp);
	return (1);
}

static char	*next_color(char **color)
{
	char	*tmp;

	tmp = *color;
	if (!(ft_strncmp(*color, BRED, 4)))
		*color = ft_strdup(BYELL);
	else if (!(ft_strncmp(*color, BYELL, 4)))
		*color = ft_strdup(BGREEN);
	else if (!(ft_strncmp(*color, BGREEN, 4)))
		*color = ft_strdup(BLBLUE);
	else if (!(ft_strncmp(*color, BLBLUE, 4)))
		*color = ft_strdup(BBLUE);
	else if (!(ft_strncmp(*color, BBLUE, 4)))
		*color = ft_strdup(BMAJ);
	else if (!(ft_strncmp(*color, BMAJ, 4)))
		*color = ft_strdup(BRED);
	free(tmp);
	return (*color);
}

int			pf_print_the_rainbow(char *expr, int count)
{
	int		i;
	char	*color;

	i = 0;
	color = ft_strdup(BRED);
	write(1, "\e[30m \r", 7);
	while (i < count)
	{
		i += put_char(color, expr[i]);
		if (expr[i] == '\n')
		{
			i += put_char("\e[0m ", expr[i]);
			write(1, "\e[30m \r", 7);
			color = next_color(&color);
		}
	}
	return (count);
}
