/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:15:48 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:19:29 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

static int		add_flag(int **flags, unsigned int flag)
{
	if (flag == F_H)
		**flags ^= (**flags & (F_H | F_HH)) ? (F_H | F_HH) : F_H;
	else if (flag == F_L)
		**flags ^= (**flags & (F_L | F_LL)) ? (F_L | F_LL) : F_L;
	else
		**flags |= flag;
	return (1);
}

static int		c_z(char *zeros)
{
	int		z;

	if (*zeros != '0' && *zeros != '-')
		return (1);
	z = 0;
	if (*zeros == '-')
	{
		zeros++;
		z += (*zeros == '0' ? 1 : 2);
	}
	while (*(zeros++) == '0')
		z++;
	return (z);
}

static int		flagger(int **flags, char *c, char *mset)
{
	if (!(ft_strchr(mset, *c)))
		return (add_flag(flags, F_ERR));
	if (*c == '+' || *c == ' ')
		return (add_flag(flags, (*c == '+' ? F_PLUS : F_SPACE)));
	else if (*c == '#' || *c == '0')
		return (add_flag(flags, (*c == '#' ? F_ALT : F_ZPAD)));
	else if (*c == 'h' || *c == 'l')
		return (add_flag(flags, (*c == 'h' ? F_H : F_L)));
	else if (*c == 'z' || *c == 'j')
		return (add_flag(flags, (*c == 'z' ? F_Z : F_J)));
	else if (*c == '-' || *c == 'L')
		return (add_flag(flags, (*c == '-' ? F_RPAD : F_LD)));
	else if (ft_isdigit(*c) || *c == '.')
	{
		add_flag(flags, (*c == '.' ? F_PREC : F_FW));
		if (*c == '.')
		{
			return ((int)(ft_intlen(((*flags)[1] = ft_atoi(c + 1)))) +
					c_z(c + 1));
		}
		(*flags)[2] = ft_atoi(c) > (*flags)[2] ? ft_atoi(c) : (*flags)[2];
		return ((int)(ft_intlen(ft_atoi(c))));
	}
	return (0);
}

int				pf_get_flags(char *expr, int **flags)
{
	char	d;
	char	*mset;
	int		chk;

	if (!(*flags = (int *)malloc(sizeof(int) * 4)))
		return (pf_malloc_error(0));
	if (!(mset = ft_strdup(MSET)))
		return (pf_malloc_error(1, flags));
	(*flags)[0] = 0;
	(*flags)[1] = 0;
	(*flags)[2] = 0;
	(*flags)[3] = 0;
	d = *expr;
	expr++;
	while (*expr && *expr != d && !((*flags)[0] & F_ERR))
	{
		if (!(chk = flagger(flags, expr, mset)))
			return (pf_malloc_error(2, flags, mset));
		expr += chk;
	}
	free(mset);
	return (1);
}
