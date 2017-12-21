/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:25:08 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:55:50 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <inttypes.h>

static size_t	int_len(intmax_t nb)
{
	int				count;
	uintmax_t		n;

	n = nb < 0 ? -nb : nb;
	count = nb < 0 ? 1 : 0;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}

char			*ft_itoa(intmax_t n)
{
	size_t			len;
	uintmax_t		nb;
	char			*s;

	len = int_len(n);
	nb = n < 0 ? -n : n;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (n < 0)
		s[0] = '-';
	while (len > (n < 0 ? 1 : 0))
	{
		s[len - 1] = (nb % 10) + '0';
		len--;
		nb /= 10;
	}
	return (s);
}
