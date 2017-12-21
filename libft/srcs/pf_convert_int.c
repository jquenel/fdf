/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:16:17 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:39:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <inttypes.h>
#include <sys/types.h>
#include <stdlib.h>

static int	convert(int *flags, char **dst, intmax_t arg)
{
	intmax_t nb;

	nb = (intmax_t)arg;
	if (*flags & F_J)
		*dst = ft_itoa(nb);
	else if (*flags & F_LL)
		*dst = ft_itoa((long long int)nb);
	else if (*flags & F_L)
		*dst = ft_itoa((long int)nb);
	else if (*flags & F_Z)
		*dst = ft_itoa((ssize_t)nb);
	else if (*flags & F_HH)
		*dst = ft_itoa((char)nb);
	else if (*flags & F_H)
		*dst = ft_itoa((short)nb);
	else
		*dst = ft_itoa((int)nb);
	if (!*dst)
		return (pf_malloc_error(0));
	return ((int)(ft_strlen(*dst)));
}

int			pf_convert_int(char *expr, char **str, va_list *arg)
{
	int			count;
	int			*flags;
	intmax_t	n;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (*expr == 'D')
		*flags |= F_L;
	n = va_arg(*arg, intmax_t);
	count = convert(flags, str, n);
	if ((*flags & F_PREC) && flags[1] == 0 && **str == '0')
	{
		**str = '\0';
		count = 0;
	}
	else if ((*flags & F_PREC) && flags[1] > (count - (**str == '-' ? 1 : 0)) &&
			flags[1] > 0)
		count = pf_flag_nprec(str, count, flags[1]);
	if ((*flags & (F_PLUS | F_SPACE)) && (*str)[0] && *(str)[0] != '-')
		count = pf_flag_signed(str, count, *flags);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_num_minfw(str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
