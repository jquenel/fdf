/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:25 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/10 20:29:29 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

size_t					ft_strlen(const char *s)
{
	size_t			len;
	uint64_t		*str64;
	uint32_t		*str32;

	len = 0;
	str64 = (uint64_t *)s;
	while (!((*str64 - 0x0101010101010101) & ~(*str64) & 0x8080808080808080))
	{
		str64++;
		len += 8;
	}
	str32 = (uint32_t *)str64;
	while (!((*str32 - 0x01010101) & ~(*str32) & 0x80808080))
	{
		str32++;
		len += 4;
	}
	s = (char *)str32;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}
