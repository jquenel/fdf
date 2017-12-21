/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:25:08 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:55:37 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t		ft_intlen(int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = nb < 0 ? -nb : nb;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count + 1);
}
