/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:56:22 by oburato           #+#    #+#             */
/*   Updated: 2022/07/23 22:10:47 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
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
	return (dest);
}
