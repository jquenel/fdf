/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:01:36 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:48 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			pf_convert_percent(char *expr, char **str, va_list *arg)
{
	int		count;
	int		*flags;

	(void)arg;
	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (!(*str = (char *)malloc(sizeof(char) * 2)))
		return (pf_malloc_error(0));
	(*str)[0] = '%';
	(*str)[1] = '\0';
	count = 1;
	if (*expr == 's' && (*flags & F_PREC) && flags[1] < count)
		count = pf_flag_sprec(str, flags[1]);
	if ((*flags & F_FW) && flags[2] > count)
	{
		count = pf_flag_minfw(str, flags, count, flags[2] - count);
	}
	free(flags);
	return (count);
}
