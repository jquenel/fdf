/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:25:08 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:56:58 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <inttypes.h>

static int		int_len(uintmax_t nb, size_t base)
{
	int			count;
	uintmax_t	n;

	n = nb;
	count = 0;
	while (n >= base)
	{
		n /= base;
		count++;
	}
	return (count + 1);
}

char			*ft_uitoa_base(uintmax_t n, char *bset)
{
	int			len;
	size_t		base;
	uintmax_t	nb;
	char		*s;

	base = ft_strlen(bset);
	if (base < 2)
		return (NULL);
	len = int_len(n, base);
	nb = n;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		s[--len] = nb % base + 1;
		nb /= base;
	}
	len = 0;
	while (s[len])
	{
		s[len] = bset[(int)(s[len]) - 1];
		len++;
	}
	return (s);
}
