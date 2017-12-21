/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:01:24 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:56:36 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**			<<<< memjoin >>>>
**
**		Allocates sufficient memory to create a copy of s1 + s2.
**		s1 is to be placed in front of s2 (see memrjoin for reverse).
**		Both original memory blocks are freed.
**		s1 now points to the newly created memory block.
**		s2 is set to NULL.
**		Returns the length of the new memory block.
*/

int		ft_memjoin(void **s1, void *s2, size_t n1, size_t n2)
{
	int			i;
	char		*tmp;

	if (!s1 || !s2)
		return (0);
	if (!(tmp = (char *)malloc(sizeof(char) * n1 + 1)))
		return (0);
	i = -1;
	while (++i < (int)n1)
		tmp[i] = ((char *)(*s1))[i];
	free(*s1);
	if (!(*s1 = (void *)malloc(sizeof(char) * (n1 + n2 + 1))))
		return (0);
	i = -1;
	while (++i < (int)n1)
		((char *)(*s1))[i] = tmp[i];
	i = -1;
	while (++i < (int)n2)
		((char *)(*s1))[i + n1] = ((char *)s2)[i];
	((char *)(*s1))[i + n1] = '\0';
	free(s2);
	free(tmp);
	return (n1 + n2);
}
