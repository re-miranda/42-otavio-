/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 14:53:58 by oburato           #+#    #+#             */
/*   Updated: 2022/07/28 02:47:11 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_str_join_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (s1)
		while (s1[i] != '\0')
			dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	ft_free(s1);
	return (dest);
}

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
		ft_free(var.line);
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
	ft_free(var->line);
	var->line = buffer;
}

void	ft_read_bytes(t_struct *var)
{
	int	bytes;

	bytes = 1;
	while (bytes > 0 && ft_strchr(var->line, '\n') == NULL)
	{
		bytes = read(var->fd, var->buffer, 100);
		if (bytes < 0)
		{
			ft_free(var->line);
			return ;
		}
		var->buffer[bytes] = '\0';
		var->line = ft_str_join_gnl(var->line, var->buffer);
	}
}
