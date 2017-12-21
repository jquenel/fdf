/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:34:43 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/12 13:34:45 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstinsert(t_list *prev, t_list *new)
{
	t_list	*lst;

	lst = prev->next;
	prev->next = new;
	new->next = lst;
}
