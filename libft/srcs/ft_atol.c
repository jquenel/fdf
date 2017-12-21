/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 00:50:20 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/14 00:50:46 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol(char const *s)
{
	int		sign;
	long	nb;
	int		i;

	nb = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		sign = s[i] == '-' ? -1 : 1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		nb = nb * 10 + s[i] - 48;
		i++;
	}
	return (nb * sign);
}
