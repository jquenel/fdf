/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:14:55 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:56:56 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*s;

	if ((s = (char *)malloc(sizeof(char) * (size + 1))))
	{
		ft_bzero((void *)s, size + 1);
		return (s);
	}
	return (NULL);
}
