/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:15:48 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:33:05 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static int	convert_help(char **c_str, int count, char *tab, va_list *ap)
{
	t_clist		*tl;
	t_clist		*tltmp;
	int			chk;
	char		*tmp;

	if (!(pf_init_clist(&tl)))
		return (pf_malloc_error(0));
	tltmp = tl;
	while (tl->set)
	{
		if (ft_strchr(tl->set, tab[0]))
		{
			if (*tab == '\1')
				chk = tl->f(tab, &tmp, 0);
			else
				chk = tl->f(tab, &tmp, ap);
			if (!(ft_memjoin((void *)c_str, (void *)(tmp), (size_t)count,
							(size_t)chk)))
				chk = 0;
			count += chk;
		}
		tl++;
	}
	free(tltmp);
	return (count);
}

int			pf_converter(va_list *ap, char **c_str, char **tab)
{
	int			count;

	count = 0;
	if (!(*c_str = (char *)malloc(1)))
		return (pf_malloc_error(0));
	**c_str = '\0';
	while (*tab)
	{
		count = convert_help(c_str, count, *tab, ap);
		tab++;
	}
	return (count);
}
