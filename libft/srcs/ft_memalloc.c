/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:38:11 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/12 14:20:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*fresh_mem;
	size_t	i;

	fresh_mem = (void *)malloc(size);
	if (fresh_mem == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		((char *)fresh_mem)[i] = 0;
		i++;
	}
	return (fresh_mem);
}
