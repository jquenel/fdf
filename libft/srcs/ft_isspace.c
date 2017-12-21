/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:36:48 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:55:47 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(int c)
{
	if ((unsigned char)c == ' ')
		return (1);
	if ((unsigned char)c == '\f')
		return (1);
	if ((unsigned char)c == '\n')
		return (1);
	if ((unsigned char)c == '\r')
		return (1);
	if ((unsigned char)c == '\t')
		return (1);
	if ((unsigned char)c == '\v')
		return (1);
	return (0);
}
