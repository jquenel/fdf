/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 04:53:24 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/16 04:56:48 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_tabdel(void *tab)
{
	char	**tmp;
	char	*str;

	tmp = (char **)tab;
	while (*tmp)
	{
		str = *tmp;
		*tmp = NULL;
		free(str);
		tmp++;
	}
	free(tab);
}
