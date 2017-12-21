/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:38:53 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/10 20:01:41 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static unsigned long	detect_char(unsigned long cmp)
{
	return ((cmp - 0x0101010101010101) & ~cmp & 0x8080808080808080);
}

static unsigned long	get_mask(unsigned char c)
{
	unsigned long	mask;

	mask = (c << 8) | c;
	mask = (mask << 16) | mask;
	return ((mask << 32) | mask);
}

static void				*byte_memccpy(void *src, void *dst, unsigned char c,
												size_t n)
{
	while (n--)
	{
		(*((unsigned char *)dst) = *((unsigned char *)src));
		if (*((unsigned char *)src) == c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned long	mask;
	unsigned long	*str;
	unsigned long	*ldest;
	unsigned char	d;

	str = (unsigned long *)src;
	ldest = (unsigned long *)dest;
	d = (unsigned char)c;
	if (n >= 8)
	{
		mask = get_mask(d);
		while (n >= 8)
		{
			if (detect_char(*str ^ mask))
				break ;
			*ldest = *str;
			ldest++;
			str++;
			n -= 8;
		}
	}
	return (byte_memccpy((void *)str, (void *)ldest, d, n));
}
