/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_modifs02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:37:34 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 00:10:34 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_flag_alt_hex(char **str, int count, char id)
{
	char	*tmp;
	int		i;

	if (!(tmp = (char *)malloc(sizeof(char) * (count + 3))))
		return (pf_malloc_error(0));
	i = count;
	while (i--)
		tmp[i + 2] = (*str)[i];
	tmp[count + 2] = '\0';
	tmp[0] = '0';
	tmp[1] = id == 'p' ? 'x' : id;
	free(*str);
	if (!(*str = (char *)malloc(sizeof(char) * (count + 3))))
		return (pf_malloc_error(1, tmp));
	while (i < count + 3)
	{
		(*str)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (count + 2);
}

int		pf_flag_alt_oct(char **str, int count)
{
	char	*tmp;
	int		i;

	if (!(tmp = (char *)malloc(sizeof(char) * (count + 2))))
		return (pf_malloc_error(0));
	i = count;
	while (i--)
		tmp[i + 1] = (*str)[i];
	tmp[count + 1] = '\0';
	tmp[0] = '0';
	free(*str);
	if (!(*str = (char *)malloc(sizeof(char) * (count + 2))))
		return (pf_malloc_error(1, tmp));
	while (i < count + 2)
	{
		(*str)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (count + 1);
}
