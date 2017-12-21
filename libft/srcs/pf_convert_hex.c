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
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>

static int	convert(int *flags, char **dst, uintmax_t arg, char id)
{
	char	*charset;

	if (!(charset = pf_init_charset(id)))
		return (0);
	if (*flags & F_LL)
		*dst = ft_uitoa_base((unsigned long long int)arg, charset);
	else if (*flags & F_L)
		*dst = ft_uitoa_base((unsigned long int)arg, charset);
	else if (*flags & F_HH)
		*dst = ft_uitoa_base((unsigned char)arg, charset);
	else if (*flags & F_H)
		*dst = ft_uitoa_base((unsigned short)arg, charset);
	else if (*flags & F_J)
		*dst = ft_uitoa_base(arg, charset);
	else if (*flags & F_Z)
		*dst = ft_uitoa_base((size_t)arg, charset);
	else
		*dst = ft_uitoa_base((unsigned int)arg, charset);
	free(charset);
	if (!*dst)
		return (pf_malloc_error(0));
	return (ft_strlen(*dst));
}

int			pf_convert_hex(char *expr, char **str, va_list *arg)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	count = convert(flags, str, va_arg(*arg, uintmax_t), *expr);
	if ((*str)[0] == '0' && (*str)[1] == '\0' && (*flags & F_PREC))
	{
		**str = '\0';
		count = 0;
	}
	if ((*flags & F_PREC) && flags[1] > count && flags[1] > 0)
		count = pf_flag_nprec(str, count, flags[1]);
	if ((*flags & F_ALT) && (ft_atoi(*str)))
		count = pf_flag_alt_hex(str, count, *expr);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_hex_minfw(str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
