/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:43 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/11 06:25:00 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

unsigned long	detect_null(unsigned long n)
{
	return ((n - 0x0101010101010101) & ~n & 0x8080808080808080);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned long	*str1;
	unsigned long	*str2;

	str1 = (unsigned long *)s1;
	str2 = (unsigned long *)s2;
	while (!(detect_null(*str1) || detect_null(*str2)) && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	s1 = (char *)str1;
	s2 = (char *)str2;
	while (*s1 && *s2)
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	return ((int)((unsigned char)(*s1) - (unsigned char)(*s2)));
}
