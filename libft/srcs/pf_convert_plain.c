/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_todo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:01:50 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:41:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			get_wrong_converter(char *expr, char **str, char *set)
{
	int		*flags;
	int		count;
	char	*tmp;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	*flags ^= *flags & F_ERR ? F_ERR : 0;
	expr++;
	while (*expr && ft_strchr(set, *expr))
		expr++;
	if ((*flags & F_FW))
	{
		if (!(*str = ft_strdup(expr)))
			return (pf_malloc_error(1, flags));
		count = pf_flag_minfw(str, flags, 1, flags[2] - 1);
		expr++;
		tmp = *str;
		if (!(*str = ft_strjoin(*str, expr)))
			return (pf_malloc_error(2, tmp, flags));
		free(tmp);
	}
	else if (!(*str = ft_strdup(expr)))
		return (pf_malloc_error(1, flags));
	free(flags);
	return ((int)(ft_strlen(*str)));
}

int			pf_convert_plain(char *expr, char **str, va_list *arg)
{
	int		size;
	char	*set;

	(void)arg;
	if (!(set = ft_strdup(MSET)))
		return (pf_malloc_error(0));
	if (*(expr) == '\2')
		size = get_wrong_converter(expr, str, set);
	else
	{
		expr++;
		size = (int)(ft_strlen(expr));
		if (!(*str = (char *)malloc(sizeof(char) * (unsigned long)(size + 1))))
			return (pf_malloc_error(1, set));
		while (*expr)
			*((*str)++) = *(expr++);
		**str = '\0';
		(*str) -= size;
	}
	free(set);
	return (size);
}
