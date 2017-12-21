/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:49:30 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 23:29:49 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
**		             [ PFparser ]
**
**		Parsing utility for ft_printf.
**		Takes in an expression, and splits it into
**		its different parts, depending on the list of
**		available converting flag.
**		Each string will start by the appropriate flag as
**		a character, and 1 if it is to be considered as
**		a plain string.
*/

/*
**		The get_tab function compares the last character
**		read by the calling function, and copies it to dst[0]
**		if it is found in the set of flags (fset). Else, it sets
**		dst[0] to a default value of 1.
**
**		It then copies n characters from the source (up to the
**		delimiter found in the calling function).
*/

static int	percentpercent(char **dst, char *src, int n, char *mset)
{
	int		i;

	i = 0;
	while (ft_strchr(mset, src[i]))
		i++;
	if (src[i] != '%')
		(*dst)[0] = '\2';
	i = 0;
	while (++i < ((*dst)[0] == '\2' ? n : n + 1))
		(*dst)[i] = src[i - 1];
	(*dst)[i] = '\0';
	return ((*dst)[0] == '\2' ? n - 1 : n);
}

static int	get_tab(char **dst, char *src, int n, char f)
{
	int			i;
	char		*mset;

	if (!(*dst = (char *)malloc(sizeof(char) * (unsigned long)(n + 1))))
		return (pf_malloc_error(0) + n);
	if (!(mset = ft_strdup(MSET)))
		return (pf_malloc_error(0) + n);
	(*dst)[0] = f;
	i = 1;
	while (i < n + 1 && src[i - 1] && src[n - 1] != '%')
	{
		if (src[i - 1] != f && !(ft_strchr(mset, src[i - 1])) && f != '\1')
			(*dst)[0] = '\2';
		(*dst)[i] = src[i - 1];
		i++;
	}
	if (src[n - 1] == '%')
		n = percentpercent(dst, src, n, mset);
	else
		(*dst)[i] = '\0';
	free(mset);
	return (n);
}

/*
**		This split_expr function looks for delimiter.
**		It then calls get_tab in order to allocate the
**		memory and copy the string.
*/

static void	split_input(char *s, char **tab, char *fset)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			i = (int)(ft_strcspn(++s, fset));
			if (s[i] == '\0')
				get_tab(tab++, s, i, '\2');
			else
			{
				i++;
				i = get_tab(tab++, s, i, s[i - 1]);
			}
			s += i;
		}
		else
		{
			i = ft_strcspn(s, "%");
			get_tab(tab++, s, i, '\1');
			s += i;
		}
	}
	*tab = NULL;
}

/*
**		The parser function itself only initializes the tab variables
**		used in the subfunction before calling it.
*/

char		**pf_parser(char *usr_in, char **tab)
{
	int		i;
	char	*fset;

	i = 0;
	while (usr_in[i])
		i++;
	if (!(tab = (char **)malloc(sizeof(char *) * (unsigned long)(i + 1))))
		return (pf_malloc_error(0) ? NULL : NULL);
	while (i + 1)
		tab[i--] = NULL;
	if (!(fset = ft_strdup(FSET)))
		return (pf_malloc_error(0) ? NULL : NULL);
	split_input(usr_in, tab, fset);
	free(fset);
	return (tab);
}
