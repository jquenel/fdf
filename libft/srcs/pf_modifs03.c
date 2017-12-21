/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifs01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:25:18 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 20:14:52 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	insert_fw(char **str, char *pad, int size, int len)
{
	char	*tmp;
	int		i;

	if (!(tmp = (char *)malloc(sizeof(char) * (size + len + 1))))
		return (pf_malloc_error(0));
	tmp[0] = (*str)[0];
	tmp[1] = (*str)[1];
	i = -1;
	while (++i < len)
		tmp[i + 2] = pad[i];
	i = 1;
	while (++i < size)
		tmp[i + len] = (*str)[i];
	tmp[i + len] = '\0';
	free(*str);
	if (!(*str = (char *)malloc(sizeof(char) * (size + len + 1))))
		return (pf_malloc_error(1, tmp));
	i = -1;
	while (++i < size + len + 1)
		(*str)[i] = tmp[i];
	free(tmp);
	return (size + len);
}

int			pf_flag_hex_minfw(char **str, int *flags, int size, int len)
{
	char	*pad;
	int		i;
	char	c;

	if ((*flags & F_PREC) && flags[1] >= 0)
		c = ' ';
	else
		c = (*flags & F_ZPAD) && !(*flags & F_RPAD) ? '0' : ' ';
	if (!(pad = (char *)malloc(sizeof(char) * (len + 1))))
		return (pf_malloc_error(0));
	i = len;
	while (i--)
		pad[i] = c;
	if (*flags & F_RPAD)
		i = ft_memjoin((void *)str, (void *)pad, size, len);
	else
		i = c == '0' && (*flags & F_ALT) ? insert_fw(str, pad, size, len) :
			ft_memrjoin((void *)str, (void *)pad, size, len);
	return (i);
}

int			pf_flag_num_minfw(char **str, int *flags, int size, int len)
{
	char	*pad;
	int		i;
	char	c;

	if ((*flags & F_ZPAD) && !(*flags & (F_RPAD | F_PREC)))
		i = pf_flag_nprec(str, size,
		size + len - ((**str == '-' || **str == ' ' || **str == '+') ? 1 : 0));
	else
	{
		c = ' ';
		if (!(pad = (char *)malloc(sizeof(char) * (len + 1))))
			return (pf_malloc_error(0));
		i = len;
		while (i--)
			pad[i] = c;
		if (*flags & F_RPAD)
			i = ft_memjoin((void *)str, (void *)pad, size, len);
		else
			i = ft_memrjoin((void *)str, (void *)pad, size, len);
	}
	return (i);
}

int			pf_flag_minfw(char **str, int *flags, int size, int len)
{
	char	*pad;
	int		i;
	char	c;

	c = (*flags & F_ZPAD) && !(*flags & F_RPAD) ? '0' : ' ';
	if (!(pad = (char *)malloc(sizeof(char) * (len + 1))))
		return (pf_malloc_error(0));
	i = -1;
	while (++i < len)
		pad[i] = c;
	pad[i] = '\0';
	if (*flags & F_RPAD)
		i = ft_memjoin((void *)str, (void *)pad, size, len);
	else
		i = ft_memrjoin((void *)str, (void *)pad, size, len);
	return (i);
}
