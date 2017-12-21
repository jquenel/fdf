/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:08:38 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:42:37 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <math.h>

static void	long_double(char *longer, long l)
{
	long long	i;

	i = 0;
	if (l--)
	{
		while (i++ < 2000000000)
			long_double(longer, l);
	}
	else
		return ;
}

static int	add_point(char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '.')
		i++;
	if (!(*str)[i])
	{
		tmp = *str;
		if (!(*str = ft_strjoin(*str, ".")))
			return (pf_malloc_error(1, tmp));
		free(tmp);
	}
	return (ft_strlen(*str));
}

static char	*get_extra_dec(float tf, int prec)
{
	char	*extra;
	int		i;

	i = 0;
	if (!(extra = (char *)malloc(sizeof(char) * (unsigned long)(prec + 1))))
		return (pf_malloc_error(0) ? NULL : NULL);
	while (prec--)
	{
		tf *= 10.0;
		extra[i] = (char)tf + '0';
		tf -= (char)tf;
		if ((double)tf * 10.0 >= 5.0 && !prec)
			extra[i] = extra[i] != '9' ? extra[i] + 1 : '9';
		i++;
	}
	extra[i] = '\0';
	return (extra);
}

static int	convert(int *flags, char **str, float n)
{
	size_t		exp;
	char		*tmp;
	float		tf;

	tf = n >= 0 ? n : -n;
	exp = 1;
	while ((tf /= 10.0) > 1)
		exp++;
	tf = n >= 0 ? n : -n;
	if (!(*str = (char *)malloc(sizeof(char) * (exp + (flags[1] ? 2 : 1)))))
		return (pf_malloc_error(0));
	(*str)[exp] = flags[1] ? '.' : '\0';
	if (flags[1])
		(*str)[exp + 1] = '\0';
	while (exp--)
	{
		(*str)[exp] = ((int)tf) % 10 + '0';
		if (tf > 1)
			tf /= 10.0;
	}
	tmp = *str;
	if (!(*str = ft_strjoin(*str, get_extra_dec(n - (int)n, flags[1]))))
		return (pf_malloc_error(1, tmp));
	free(tmp);
	return (ft_strlen(*str));
}

int			pf_convert_float(char *expr, char **str, va_list *ap)
{
	int		count;
	int		*flags;
	float	n;

	if (!(pf_get_flags(expr, &flags)))
		return (pf_malloc_error(0));
	if (!(*flags & F_PREC))
		flags[1] = 6;
	n = (float)(va_arg(*ap, double));
	if (*flags & (F_L | F_LD | F_LL))
		n *= 2.0;
	if (*flags & F_LD)
		long_double("super long", 1);
	count = convert(flags, str, n);
	if ((*flags & (F_PLUS | F_SPACE)) && (*str)[0] && (*str)[0] != '-')
		count = pf_flag_signed(str, count, *flags);
	if ((*flags & F_ALT) && flags[1] == 0)
		count = add_point(str);
	if ((*flags & F_FW) && flags[2] > count)
		count = pf_flag_nprec(str, count, flags[2] +
				((**str == '-' || **str == '+' || **str == ' ') ? 1 : 0) - 2);
	free(flags);
	return (count);
}
