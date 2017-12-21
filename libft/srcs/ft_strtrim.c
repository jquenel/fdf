/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:40:14 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/12 16:07:42 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	t_len(char const *s)
{
	size_t	i;
	size_t	flag;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (i == len)
		return (1);
	flag = i;
	i = len - 1;
	while (ft_isspace(s[i]))
		i--;
	len = i - flag + 1;
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*trim_s;
	size_t	i;
	size_t	flag;
	size_t	len;

	if (!s)
		return (NULL);
	len = t_len(s);
	if (!(trim_s = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	flag = i;
	i = 0;
	while (i < len)
	{
		trim_s[i] = s[flag + i];
		i++;
	}
	trim_s[i] = '\0';
	return (trim_s);
}
