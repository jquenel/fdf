/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:16:17 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:48 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>
#include <stdlib.h>

static int	convert(int *flags, char **dst, uintmax_t arg)
{
	uintmax_t nb;

	nb = (uintmax_t)arg;
	if (*flags & F_J)
		*dst = ft_uitoa(nb);
	else if (*flags & F_LL)
		*dst = ft_uitoa((unsigned long long int)nb);
	else if (*flags & F_L)
		*dst = ft_uitoa((unsigned long int)nb);
	else if (*flags & F_Z)
		*dst = ft_uitoa((size_t)nb);
	else if (*flags & F_HH)
		*dst = ft_uitoa((unsigned char)nb);
	else if (*flags & F_H)
		*dst = ft_uitoa((unsigned short)nb);
	else
		*dst = ft_uitoa((unsigned int)nb);
	if (!*dst)
		return (pf_malloc_error(0));
	return (ft_strlen(*dst));
}

int			pf_convert_uint(char *expr, char **str, va_list *arg)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (*expr == 'U')
		*flags |= F_L;
	count = convert(flags, str, va_arg(*arg, uintmax_t));
	if ((*flags & F_PREC) && flags[1] == 0 && **str == '0')
	{
		**str = '\0';
		count = 0;
	}
	else if ((*flags & F_PREC) && flags[1] > count && flags[1] > 0)
		count = pf_flag_nprec(str, count, flags[1]);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_num_minfw(str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
