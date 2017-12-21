/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:25:08 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:56:57 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <inttypes.h>

static size_t	int_len(uintmax_t nb)
{
	int				count;
	uintmax_t		n;

	n = nb;
	count = 0;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char			*ft_uitoa(uintmax_t n)
{
	size_t			len;
	uintmax_t		nb;
	char			*s;

	len = int_len(n);
	nb = n;
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (len > 0)
	{
		s[len - 1] = (nb % 10) + '0';
		len--;
		nb /= 10;
	}
	return (s);
}
