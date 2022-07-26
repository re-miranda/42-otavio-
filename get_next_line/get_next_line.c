/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:53:58 by oburato           #+#    #+#             */
/*   Updated: 2022/07/24 20:35:37 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_struct	var;
	char			*result;

	var.fd = fd;
	if (var.fd < 0 || 100 <= 0 || read(var.fd, 0, 0) == -1)
		return (NULL);
	ft_read_bytes(&var);
	result = ft_get_line(&var);
	if (!*var.line)
	{
		free(var.line);
		var.line = NULL;
		return (NULL);
	}
	ft_get_buffer(&var);
	return (result);
}

char	*ft_get_line(t_struct *var)
{
	char	*result;

	var->index = 0;
	var->size = 0;
	if (!*var->line)
		return (NULL);
	while (var->line[var->size] && var->line[var->size] != '\n')
		var->size++;
	result = (char *)malloc(sizeof(char) * (var->size + 2));
	if (!result)
		return (NULL);
	while (var->line[var->index] && var->line[var->index] != '\n')
	{
		result[var->index] = var->line[var->index];
		var->index++;
	}
	if (var->line[var->index] == '\n')
	{
		result[var->index] = '\n';
		var->index++;
	}
	result[var->index] = '\0';
	return (result);
}

void	ft_get_buffer(t_struct *var)
{
	char	*buffer;
	int		len;

	var->size = 0;
	var->index = 0;
	len = ft_strlen(var->line);
	while (var->line[var->size] && var->line[var->size] != '\n')
		var->size++;
	buffer = (char *)malloc((sizeof(char) * (len - var->size) + 1));
	if (!buffer)
	{
		var->line = NULL;
		return ;
	}
	if (var->line[var->size] == '\n')
		var->size++;
	while (var->line[var->size])
		buffer[var->index++] = var->line[var->size++];
	buffer[var->index] = '\0';
	free(var->line);
	var->line = buffer;
}
