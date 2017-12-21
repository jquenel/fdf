/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:07 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/13 10:05:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		len;

	i = ft_strlen(dest);
	len = ft_strlen(src) + (size < i ? size : i);
	j = 0;
	while ((int)i < (int)(size - 1))
	{
		dest[i++] = (src[j] ? src[j] : '\0');
		if (src[j])
			j++;
	}
	dest[i] = '\0';
	return (len);
}
