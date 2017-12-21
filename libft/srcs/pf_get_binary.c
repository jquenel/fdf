/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:22:52 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:16:02 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*get_binary64(uintmax_t data)
{
	char	*bin;
	int64_t	nb;
	int64_t	mask;
	int		i;

	nb = (int32_t)data;
	if (!(bin = (char *)malloc(sizeof(char) * 65)))
		return (pf_malloc_error(0) ? NULL : NULL);
	mask = 0x8000000000000000;
	i = 0;
	while (mask)
	{
		bin[i++] = nb & mask ? '1' : '0';
		mask = (mask >> 1) ^ (mask & 0x8000000000000000 ? mask : 0);
	}
	bin[i] = '\0';
	return (bin);
}

static char	*get_binary32(uintmax_t data)
{
	char	*bin;
	int32_t	nb;
	int32_t	mask;
	int		i;

	nb = (int32_t)data;
	if (!(bin = (char *)malloc(sizeof(char) * 33)))
		return (pf_malloc_error(0) ? NULL : NULL);
	mask = 0x80000000;
	i = 0;
	while (mask)
	{
		bin[i++] = nb & mask ? '1' : '0';
		mask = (mask >> 1) ^ (mask & 0x80000000 ? mask : 0);
	}
	bin[i] = '\0';
	return (bin);
}

static char	*get_binary16(uintmax_t data)
{
	char	*bin;
	int16_t	nb;
	int16_t	mask;
	int		i;

	nb = (int16_t)data;
	if (!(bin = (char *)malloc(sizeof(char) * 17)))
		return (pf_malloc_error(0) ? NULL : NULL);
	mask = 0x8000;
	i = 0;
	while (mask)
	{
		bin[i++] = nb & mask ? '1' : '0';
		mask = (mask >> 1) ^ (mask & 0x8000 ? mask : 0);
	}
	bin[i] = '\0';
	return (bin);
}

static char	*get_binary8(uintmax_t data)
{
	char	*bin;
	char	c;
	char	mask;
	int		i;

	c = (char)data;
	if (!(bin = (char *)malloc(sizeof(char) * 9)))
		return (pf_malloc_error(0) ? NULL : NULL);
	mask = 0x80;
	i = 0;
	while (mask)
	{
		bin[i++] = c & mask ? '1' : '0';
		mask = (mask >> 1) ^ (mask & 0x80 ? mask : 0);
	}
	bin[i] = '\0';
	return (bin);
}

int			pf_get_binary(int *flags, char **str, uintmax_t data)
{
	if (*flags & F_LL)
		*str = get_binary64(data);
	else if (*flags & F_L)
		*str = get_binary32(data);
	else if (*flags & (F_HH | F_H))
		*str = get_binary8(data);
	else
		*str = get_binary16(data);
	return (ft_strlen(*str));
}
