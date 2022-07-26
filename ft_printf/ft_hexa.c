/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:45:34 by oburato           #+#    #+#             */
/*   Updated: 2022/07/23 19:45:51 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_len(unsigned long int number)
{
	int	lenght;

	lenght = 1;
	if (number == 0)
		return (1);
	while (number / 16 > 0)
	{
		lenght = lenght + 1;
		number = number / 16;
	}
	return (lenght);
}

int	ft_print_hexa(size_t number, const char *base)
{
	char	*str;
	int		lenght;

	lenght = ft_hexa_len(number);
	str = malloc(sizeof(char) * (lenght + 1));
	str[lenght] = '\0';
	while (lenght != 0)
	{
		lenght--;
		str[lenght] = base[number % 16];
		number /= 16;
	}
	lenght = ft_print_string(str);
	free(str);
	return (lenght);
}
