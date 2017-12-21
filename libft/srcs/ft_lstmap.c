/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:13:28 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/18 12:07:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*blist;

	if (!lst || !(*f))
		return (NULL);
	blist = (*f)(lst);
	while ((lst = lst->next))
		ft_lstpushback(&blist, (*f)(lst));
	return (blist);
}
