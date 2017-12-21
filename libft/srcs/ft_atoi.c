/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:22:25 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/06 18:53:09 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(char const *s)
{
	int		sign;
	int		nb;
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
