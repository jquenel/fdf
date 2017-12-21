/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:55:54 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:53 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	convert_single(char **str, char arg)
{
	if (!(*str = (char *)malloc(sizeof(char) * 2)))
		return (pf_malloc_error(0));
	(*str)[0] = arg;
	(*str)[1] = '\0';
	return (1);
}

static int	convert_string(char **str, char *arg)
{
	if (!arg)
	{
		if (!(*str = ft_strdup("(null)")))
			return (pf_malloc_error(0));
	}
	else if (!(*str = ft_strdup(arg)))
		return (pf_malloc_error(0));
	return (ft_strlen(*str));
}

int			pf_convert_char(char *expr, char **c_str, va_list *ap)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (*flags & (F_L | F_LL))
	{
		free(flags);
		return (pf_convert_wchar(expr, c_str, ap));
	}
	if (*expr == 'c')
		count = convert_single(c_str, (char)va_arg(*ap, int));
	else
		count = convert_string(c_str, va_arg(*ap, char *));
	if (*expr == 's' && (*flags & F_PREC) && flags[1] < count)
		count = pf_flag_sprec(c_str, flags[1]);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_minfw(c_str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
