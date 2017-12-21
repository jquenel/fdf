/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:57:48 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:48 by jquenel          ###   ########.fr       */
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

static int	get_wchar(int c, char **wchar, int mbcmax)
{
	int		n;
	int		r;

	n = 0;
	if (!(*wchar = (char *)malloc(sizeof(char) * 5)))
		return (0);
	if (c < 128 || (c < 256 && mbcmax == 1))
		n = 1;
	else if ((n = 4) && mbcmax == 4 && (c > 0xffff) && (c <= 0x1fffff))
		c = (c & 0x3f) | ((c << 2) & 0x3f00) | ((c << 4) & 0x3f0000) |
			((c << 6) & 0x7000000) | 0xf0808080;
	else if ((n = 3) && mbcmax >= 3 && (c > 0x7ff) & (c <= 0xffff))
		c = (c & 0x3f) | ((c << 2) & 0x3f00) | ((c << 4) & 0xf0000) | 0xe08080;
	else if ((n = 2) && mbcmax >= 2 && (c <= 0x7ff))
		c = (c & 0x3f) | ((c << 2) & 0x1f00) | 0xc080;
	else
		return (pf_malloc_error(0));
	r = n;
	while (n--)
		(*wchar)[r - n - 1] = ((c >> (8 * n)) & 0xff);
	(*wchar)[r] = '\0';
	return (r);
}

static int	null_string(char **c_str)
{
	if (!(*c_str = ft_strdup("(null)")))
		return (pf_malloc_error(0));
	return (6);
}

static int	convert_string(char **c_str, int *wchar, int *flags)
{
	char	*tmp1;
	char	*tmp2;
	int		count;
	int		n;
	int		i;

	i = *flags & F_PREC ? flags[1] : 1;
	count = 0;
	n = 1;
	*c_str = NULL;
	while (wchar && *wchar && i && n)
	{
		tmp1 = *c_str;
		if ((n = get_wchar(*wchar, &tmp2, MB_CUR_MAX)))
		{
			count += n;
			*c_str = *c_str ? ft_strjoin(*c_str, tmp2) : ft_strdup(tmp2);
			if (count)
				free(tmp1);
		}
		free(tmp2);
		wchar++;
		i -= *flags & F_PREC ? 1 : 0;
	}
	return (wchar ? count : null_string(c_str));
}

int			pf_convert_wchar(char *expr, char **c_str, va_list *ap)
{
	int		count;
	int		*flags;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (*expr == 'C' || *expr == 'c')
		count = get_wchar(va_arg(*ap, int), c_str, MB_CUR_MAX);
	else
		count = convert_string(c_str, va_arg(*ap, int *), flags);
	if (*expr == 'S' && (*flags & F_PREC) && flags[1] < count)
		count = pf_flag_sprec(c_str, flags[1]);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_minfw(c_str, flags, count, flags[2] - count);
	free(flags);
	return (count);
}
