/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:39:50 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/16 02:57:06 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		malloc_and_copy(char *s, char ***tab, int words, char c)
{
	int		i;
	int		j;
	int		k;
	int		flag;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		while (s[i] && s[i] == c)
			i++;
		flag = i;
		while (s[i] && s[i] != c)
			i++;
		(*tab)[j] = (char *)malloc(sizeof(char) * (i - flag + 1));
		if ((*tab)[j] == 0)
			return (0);
		k = 0;
		while (flag < i)
			((*tab)[j])[k++] = s[flag++];
		((*tab)[j])[k] = '\0';
		j++;
	}
	return (words);
}

static int		malloc_the_array(char *s, char ***tab, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			words++;
		while (s[i] && s[i] != c)
			i++;
	}
	if (words == 0)
		return (0);
	*tab = (char**)malloc(sizeof(char *) * (words + 1));
	if (tab == NULL)
		return (0);
	(*tab)[words] = NULL;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		words;

	if (!s)
		return (NULL);
	tab = NULL;
	words = malloc_the_array((char*)s, &tab, c);
	if (words == 0)
		return (tab);
	words = malloc_and_copy((char*)s, &tab, words, c);
	return (tab);
}
