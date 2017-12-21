/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:00:39 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/07 04:01:12 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int		pf_printer(char *expr, int count)
{
	if (ft_strnstr(expr, RAINBOW, 9))
		return (pf_print_the_rainbow(&(expr[9]), count));
	else if (ft_strstr(expr, DISCO))
		return (pf_disco_time(&(expr[7]), count));
	if (expr && count)
		return ((int)(write(1, expr, count)));
	return (0);
}
