/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:39:58 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/12 14:12:57 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		n_len;

	i = 0;
	if (!(n_len = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i] && i + n_len - 1 < len)
	{
		if (ft_strncmp((char *)&((haystack[i])), needle, n_len) == 0)
			return ((char *)&((haystack[i])));
		i++;
	}
	return (NULL);
}
