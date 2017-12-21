/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:21:06 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/27 18:39:06 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
**		==========-.____./  THIS IS PUTCHAR UNICODE  \.____.-===============
**
**		To print unicode character, use setlocale(LC_ALL, "") before
**		calling ft_putchar. If you don't want or can't use setlocale,
**		remove the MB_CUR_MAX protection from this function.
**
**		For each size of unicode character, this function checks the value
**		of the int parameter, and decides to convert it into the corresponding
**		UTF-8 encryption standard.
**		The character is the written one byte at a time, and will be assembled
**		by the terminal.
*/

int		ft_putchar(int c)
{
	int		n;
	int		a;
	int		r;

	n = 0;
	r = 0;
	if (c < 128)
		r = write(1, &c, 1);
	else if ((n = 4) && MB_CUR_MAX == 4 && (c > 0xffff) && (c <= 0x1fffff))
		c = (c & 0x3f) | ((c << 2) & 0x3f00) | ((c << 4) & 0x3f0000) |
			((c << 6) & 0x7000000) | 0xf0808080;
	else if ((n = 3) && MB_CUR_MAX >= 3 && (c > 0x7ff) & (c <= 0xffff))
		c = (c & 0x3f) | ((c << 2) & 0x3f00) | ((c << 4) & 0xf0000) | 0xe08080;
	else if ((n = 2) && MB_CUR_MAX >= 2 && (c <= 0x7ff))
		c = (c & 0x3f) | ((c << 2) & 0x1f00) | 0xc080;
	while (n)
	{
		a = (c << ((4 - n) * 8)) >> 24;
		r = write(1, &a, 1);
		n--;
	}
	return (r);
}
