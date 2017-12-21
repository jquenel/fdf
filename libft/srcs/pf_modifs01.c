/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifs01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:25:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:47:03 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_flag_sprec(char **str, int p)
{
	(*str)[p] = '\0';
	return (p);
}

int		pf_flag_nprec(char **str, int size, int p)
{
	char	*prec;
	char	c;
	int		n;

	c = **str;
	p += (ft_strchr("+- ", c)) ? 1 : 0;
	if (!(prec = (char *)malloc(sizeof(char) * (size_t)(p + 1))))
		return (pf_malloc_error(0));
	n = p;
	while (n--)
		prec[n] = '0';
	if (ft_strchr("+- ", c))
		prec[0] = c;
	prec[p] = '\0';
	n = p - 1;
	while (size-- - (ft_strchr("-+ ", c) ? 1 : 0))
		prec[n--] = (*str)[size];
	free(*str);
	if (!(*str = (char *)malloc(sizeof(char) * (size_t)(p + 1))))
		return (pf_malloc_error(1, prec));
	ft_memcpy((void *)*str, (void *)prec, (size_t)(p + 1));
	free(prec);
	return (p);
}

int		pf_flag_signed(char **str, int size, int flags)
{
	char	*sign;
	int		i;

	if (!(sign = (char *)malloc(sizeof(char) * 2)))
		return (pf_malloc_error(0));
	sign[0] = flags & F_PLUS ? '+' : ' ';
	sign[1] = '\0';
	i = ft_memrjoin((void *)str, (void *)sign, (size_t)size, 1);
	return (i);
}
