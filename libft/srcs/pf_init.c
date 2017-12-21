/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_clist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:09:09 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:17:59 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_init_clist(t_clist **clist)
{
	if (!(*clist = (t_clist *)malloc(sizeof(t_clist) * (CLIST_SIZE + 1))))
		return (pf_malloc_error(0));
	(*clist)[0] = (t_clist){.set = "diD", .f = &pf_convert_int};
	(*clist)[1] = (t_clist){.set = "uU", .f = &pf_convert_uint};
	(*clist)[2] = (t_clist){.set = "oO", .f = &pf_convert_oct};
	(*clist)[3] = (t_clist){.set = "xX", .f = &pf_convert_hex};
	(*clist)[4] = (t_clist){.set = "cs", .f = &pf_convert_char};
	(*clist)[5] = (t_clist){.set = "CS", .f = &pf_convert_wchar};
	(*clist)[6] = (t_clist){.set = "\1\2", .f = &pf_convert_plain};
	(*clist)[7] = (t_clist){.set = "%", .f = &pf_convert_percent};
	(*clist)[8] = (t_clist){.set = "p", .f = &pf_convert_adr};
	(*clist)[9] = (t_clist){.set = "fF", .f = &pf_convert_float};
	(*clist)[10] = (t_clist){.set = "b", .f = &pf_convert_bin};
	(*clist)[11] = (t_clist){NULL, NULL};
	return (1);
}

char	*pf_init_charset(char id)
{
	char	*charset;

	charset = NULL;
	if (id == 'x' || id == 'X')
	{
		if (!(charset = (char *)malloc(sizeof(char) * 17)))
			return (pf_malloc_error(0) ? NULL : NULL);
		if (id == 'x')
			charset = ft_strncpy(charset, "0123456789abcdef", 16);
		else
			charset = ft_strncpy(charset, "0123456789ABCDEF", 16);
		charset[16] = '\0';
	}
	else if (id == 'o' || id == 'O')
	{
		if (!(charset = (char *)malloc(sizeof(char) * 9)))
			return (pf_malloc_error(0) ? NULL : NULL);
		charset = ft_strncpy(charset, "01234567", 8);
		charset[8] = '\0';
	}
	return (charset);
}
