/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:16:17 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/types.h>

static int	minfw_zero_adr(char **str, int fw)
{
	char	*tmp;
	char	*mfw;

	tmp = *str;
	if (!(mfw = (char *)malloc(sizeof(char) * (fw + 1))))
		return (pf_malloc_error(0));
	mfw[fw] = '\0';
	while (fw)
		mfw[--fw] = '0';
	if (!(*str = ft_strjoin(*str, mfw)))
		return (pf_malloc_error(1, mfw));
	free(tmp);
	free(mfw);
	return (ft_strlen(*str));
}

static int	convert(char **dst, void *arg)
{
	char	*charset;

	if (!(charset = pf_init_charset('x')))
		return (0);
	if (!arg)
	{
		if (!(*dst = ft_strdup("0")))
			return (pf_malloc_error(1, charset));
	}
	else if (!(*dst = ft_uitoa_base((unsigned long int)arg, charset)))
		return (pf_malloc_error(1, charset));
	free(charset);
	return (ft_strlen(*dst));
}

int			pf_convert_adr(char *expr, char **str, va_list *arg)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	count = convert(str, va_arg(*arg, void *));
	if ((*flags & F_PREC) && flags[1] > count && flags[1] > 0)
		count = pf_flag_nprec(str, count, flags[1]);
	else if ((*flags & F_PREC) && flags[1] == 0)
		*str[--count] = '\0';
	count = pf_flag_alt_hex(str, count, *expr);
	if ((*flags & F_FW) && flags[2] > count)
	{
		if (!(ft_strncmp(*str, "0x0", 3)) &&
				(*flags & F_ZPAD) && !(*flags & (F_PREC | F_RPAD)))
			count = minfw_zero_adr(str, flags[2] - 3);
		else
			count = pf_flag_hex_minfw(str, flags, count, flags[2] - count);
	}
	free(flags);
	return (count);
}
