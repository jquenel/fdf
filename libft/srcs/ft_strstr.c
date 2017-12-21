/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:40:06 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/12 14:13:07 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	size_t		n_len;

	i = 0;
	if (!(n_len = ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[i])
	{
		if (ft_strncmp((char *)&((haystack[i])), needle, n_len) == 0)
			return ((char *)&((haystack[i])));
		i++;
	}
	return (NULL);
}
