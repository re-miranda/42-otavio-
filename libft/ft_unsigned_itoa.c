/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:41:08 by oburato           #+#    #+#             */
/*   Updated: 2022/07/28 04:41:16 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	long	n_long;
	size_t	len;

	n_long = (long)n;
	if (n < 0)
		n_long = -n_long;
	len = ft_num_len(n_long, 1);
	if (n < 0)
		len++;
	str = (char *) malloc (len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_num_put_chr(str + len -1, n_long);
	*(str + len) = '\0';
	return (str);
}
