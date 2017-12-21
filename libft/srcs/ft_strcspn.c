/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 02:07:52 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:56:47 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strcspn(const char *s, const char *charset)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
