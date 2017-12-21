/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 01:55:21 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/11 06:10:32 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmerge(char *s1, char const *s2)
{
	char	*tmp;

	tmp = s1;
	if (!s1)
		return ((s1 = ft_strdup(s2)));
	if (!(s1 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(s1, tmp);
	ft_strcpy(&(s1[(int)(ft_strlen(tmp))]), s2);
	free(tmp);
	return (s1);
}
