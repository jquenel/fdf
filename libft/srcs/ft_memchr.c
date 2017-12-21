/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:38:33 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/10 20:24:19 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static unsigned long	detect_char(unsigned long cmp)
{
	return ((cmp - 0x0101010101010101) & ~cmp & 0x8080808080808080);
}

static unsigned long	get_mask(char c)
{
	unsigned long	mask;

	mask = (c << 8) | c;
	mask = (mask << 16) | mask;
	return ((mask << 32) | mask);
}

static void				*byte_memchr(void *s, unsigned char c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char *)s) == c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long	mask;
	unsigned long	*str;
	unsigned char	d;

	d = (unsigned char)c;
	while ((long)s & (sizeof(long) - 1))
	{
		if (!n--)
			return (NULL);
		if (*((unsigned char *)(s++)) == d)
			return ((void *)(s) - 1);
	}
	str = (unsigned long *)s;
		mask = get_mask(d);
		while (n >= 8)
		{
			if (detect_char(*str ^ mask))
				break ;
			n -= 8;
			str++;
		}
	return (byte_memchr((void *)str, d, n));
}
