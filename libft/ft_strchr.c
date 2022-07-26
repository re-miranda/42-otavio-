/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:51:38 by oburato           #+#    #+#             */
/*   Updated: 2022/07/17 03:46:20 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (0);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (0);
}
