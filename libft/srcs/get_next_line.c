/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquenel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 00:38:35 by jquenel           #+#    #+#             */
/*   Updated: 2017/11/20 15:17:08 by jquenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <unistd.h>

t_stock		*new_box(int fd)
{
	t_stock		*box;

	if (!(box = (t_stock *)malloc(sizeof(t_stock))))
		return (NULL);
	box->fd = fd;
	ft_bzero((void *)(box->buf), BUFF_SIZE + 1);
	box->next = NULL;
	return (box);
}

void		burn(t_list *book)
{
	t_list	*tmp;

	while (book)
	{
		tmp = book;
		book = book->next;
		free(tmp);
	}
}

t_stock		*get_box(t_stock **warehouse, int fd)
{
	t_stock		*temp_box;

	if (!(*warehouse))
	{
		*warehouse = new_box(fd);
		return (*warehouse);
	}
	temp_box = (*warehouse);
	while (temp_box && temp_box->fd != fd)
		temp_box = temp_box->next;
	if (!temp_box)
	{
		temp_box = new_box(fd);
		temp_box->next = (*warehouse);
		(*warehouse) = temp_box;
	}
	return (temp_box);
}

char		*get_page(char **s, t_list *book, t_stock *box)
{
	size_t		len;
	t_list		*tmp_book;

	len = 0;
	tmp_book = book;
	while (tmp_book)
	{
		len += ft_strlen((char *)(tmp_book->content));
		tmp_book = tmp_book->next;
	}
	if (!(*s = ft_strnew(len + 1)))
		return (NULL);
	tmp_book = book;
	while (tmp_book)
	{
		ft_strcat(*s, (char *)(tmp_book->content));
		if (ft_strchr((char *)(tmp_book->content), EOL))
		{
			ft_strcpy(box->buf, ft_strchr(*s, EOL) + 1);
			ft_strclr(ft_strchr(*s, EOL));
		}
		free((char *)(tmp_book->content));
		tmp_book = tmp_book->next;
	}
	return (*s);
}

int			get_next_line(const int fd, char **s)
{
	static t_stock	*warehouse;
	t_stock			*box;
	t_list			*book;
	int				checker;

	box = get_box(&warehouse, fd);
	book = *(box->buf) ?
		ft_lstnew((void *)(box->buf), ft_strlen(box->buf) + 1) : NULL;
	checker = 1;
	if (!(ft_strchr(box->buf, EOL)))
	{
		while ((checker = read(fd, box->buf, BUFF_SIZE)))
		{
			if (checker == -1)
				return (checker);
			(box->buf)[checker] = '\0';
			ft_lstpushback(&book, ft_lstnew((void *)(box->buf), checker + 1));
			if (ft_strchr(box->buf, EOL))
				break ;
		}
	}
	ft_bzero(box->buf, BUFF_SIZE + 1);
	*s = get_page(s, book, box);
	burn(book);
	return ((checker || **s) ? 1 : 0);
}
