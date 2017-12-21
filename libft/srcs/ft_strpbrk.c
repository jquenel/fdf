/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:55:03 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:17:28 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <string.h>

char	*ft_strpbrk(const char *s, const char *accept)
{
	char	*ts;
	char	*ta;

	ts = (char *)s;
	while (ts)
	{
		ta = (char *)accept;
		while (ta)
		{
			if (*ts == *ta)
				return (ts);
			ta++;
		}
		ts++;
	}
	return (NULL);
}
