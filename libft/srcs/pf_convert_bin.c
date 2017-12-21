/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:22:52 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:18:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	bin_flag_alt(char **str)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*tmp;

	len = ft_strlen(*str);
	len = len + len / 8;
	tmp = *str;
	if (!(*str = (char *)malloc(sizeof(char) * len)))
		return (pf_malloc_error(0));
	i = 0;
	k = 0;
	while (i < len)
	{
		j = 0;
		while (j++ < 8)
			(*str)[i++] = tmp[k++];
		if (i < len)
			(*str)[i++] = ' ';
	}
	(*str)[i] = '\0';
	return (len);
}

int			pf_convert_bin(char *expr, char **c_str, va_list *ap)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	count = pf_get_binary(flags, c_str, va_arg(*ap, uintmax_t));
	if (*flags & F_ALT)
		count = bin_flag_alt(c_str);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_num_minfw(c_str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
