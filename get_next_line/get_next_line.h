/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:54:11 by oburato           #+#    #+#             */
/*   Updated: 2022/07/26 06:19:25 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include "../main.h"

typedef struct s_struct {
	char	*line;
	int		index;
	int		size;
	int		fd;
	char	buffer[100 + 1];
}	t_struct;

char	*get_next_line(int fd);

char	*ft_get_line(t_struct *var);
void	ft_read_bytes(t_struct *var);
void	ft_get_buffer(t_struct *var);

#endif