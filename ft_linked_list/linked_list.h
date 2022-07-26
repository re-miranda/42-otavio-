/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:54:11 by oburato           #+#    #+#             */
/*   Updated: 2022/07/26 06:22:05 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>
# include "../main.h"

typedef struct s_buf	{
	struct s_buf *next;
	struct s_buf *back;
	char *buf_str;
	void *ptr;
}	t_buf;

#endif