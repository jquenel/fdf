/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:38:48 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/16 10:48:18 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putbits(unsigned char c)
{
	unsigned char	b;

	b = (char)128;
	while (b)
	{
		ft_putchar(c & b ? '1' : '0');
		b = b >> 1;
	}
}
