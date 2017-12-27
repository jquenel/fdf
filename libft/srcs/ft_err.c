/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:45:55 by jquenel           #+#    #+#             */
/*   Updated: 2017/12/26 15:00:00 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

void		ft_err(int c, char *err_m, int ms, ...)
{
	void		*f;
	va_list		ap;

	if (c)
	{
		va_start(ap, ms);
		ft_putendl_fd(err_m, 2);
		while (ms--)
		{
			f = va_arg(ap, void *);
			free(f);
		}
		exit(0);
	}
}
