/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:03:16 by oburato           #+#    #+#             */
/*   Updated: 2022/07/26 06:15:10 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void add(t_buf *buf, void *ptr)
{
	t_buf *novo = ft_malloc(sizeof(t_buf));
	novo->next = 0;
	novo->ptr = ptr;
	while(buf->next != 0 && buf->ptr != ptr)
		buf = buf->next;
	if (buf->ptr == ptr)
	{
		ft_free(novo);
		return ;
	}
	buf->next = novo;
	novo->back = buf;
}

void	removeNode(t_buf *buf, void *ptr)
{
	while(buf->next != 0 && buf->ptr != ptr)
		buf = buf->next;
	buf->back->next = buf->next;
	ft_free(buf);
}
