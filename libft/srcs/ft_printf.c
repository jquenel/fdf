/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 04:15:23 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:15:26 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static void	cleaner(char **tab, char *cstr)
{
	char *tmp;

	while (*tab)
	{
		tmp = *tab;
		tab++;
		free(tmp);
	}
	free(cstr);
}

int			pf_report_error(int error)
{
	static int		fatal_error;

	if (fatal_error != -1)
		fatal_error = 0;
	if (error)
		fatal_error = -1;
	return (fatal_error + 1);
}

int			pf_malloc_error(int rip, ...)
{
	va_list			fap;
	void			*target;

	va_start(fap, rip);
	while (rip--)
	{
		target = va_arg(fap, void *);
		free(target);
	}
	va_end(fap);
	pf_report_error(1);
	return (0);
}

int			ft_printf(char *usr_in, ...)
{
	va_list			ap;
	int				count;
	char			*c_str;
	char			**tab;

	c_str = NULL;
	tab = NULL;
	va_start(ap, usr_in);
	if (!(tab = pf_parser(usr_in, tab)))
		return (-1);
	count = pf_converter(&ap, &c_str, tab);
	count = pf_printer(c_str, count);
	cleaner(tab, c_str);
	free(tab);
	va_end(ap);
	return (pf_report_error(0) ? count : -1);
}
