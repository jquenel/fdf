/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:38:24 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/10 16:55:01 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <inttypes.h>

inline static int	cmp08(const void *s1, const void *s2, size_t n)
{
	while (n >= sizeof(unsigned char))
	{
		if (*((unsigned char *)s1) ^ *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1 += sizeof(unsigned char);
		s2 += sizeof(unsigned char);
		n -= sizeof(unsigned char);
	}
	return (0);
}

inline static int	cmp16(const void *s1, const void *s2, size_t n)
{
	while (n >= sizeof(uint16_t))
	{
		if (*((uint16_t *)s1) ^ *((uint16_t *)s2))
			return (cmp08(s1, s2, n));
		s1 += sizeof(uint16_t);
		s2 += sizeof(uint16_t);
		n -= sizeof(uint16_t);
	}
	if (n == 0)
		return (0);
	return (cmp08(s1, s2, n));
}

inline static int	cmp32(const void *s1, const void *s2, size_t n)
{
	while (n >= sizeof(uint32_t))
	{
		if (*((uint32_t *)s1) ^ *((uint32_t *)s2))
			return (cmp16(s1, s2, n));
		s1 += sizeof(uint32_t);
		s2 += sizeof(uint32_t);
		n -= sizeof(uint32_t);
	}
	if (n == 0)
		return (0);
	return (cmp16(s1, s2, n));
}

inline static int	cmp64(const void *s1, const void *s2, size_t n)
{
	while (n >= sizeof(uint64_t))
	{
		if (*((uint64_t *)s1) ^ *((uint64_t *)s2))
			return (cmp32(s1, s2, n));
		s1 += sizeof(uint64_t);
		s2 += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	if (n == 0)
		return (0);
	return (cmp32(s1, s2, n));
}

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	return (cmp64(s1, s2, n));
}
