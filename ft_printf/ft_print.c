/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:46:27 by oburato           #+#    #+#             */
/*   Updated: 2022/07/23 19:46:41 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int	lenght;

	lenght = 0;
	if (str == NULL)
	{
		lenght += write(1, "(null)", 6);
		return (lenght);
	}
	while (*str != '\0')
	{
		lenght += write(1, *&str, 1);
		str++;
	}
	return (lenght);
}

int	ft_print_number(int number)
{
	int		lenght;
	char	*str;

	lenght = 0;
	str = ft_itoa(number);
	lenght += ft_print_string(str);
	free(str);
	return (lenght);
}

int	ft_print_unsigned_number(unsigned int number)
{
	int		lenght;
	char	*str;

	lenght = 0;
	str = ft_unsigned_itoa(number);
	lenght += ft_print_string(str);
	free(str);
	return (lenght);
}

int	ft_print_pointer(size_t pointer)
{
	int	lenght;

	lenght = 0;
	if (!pointer)
	{
		lenght += write(1, "(nil)", 5);
		return (lenght);
	}
	lenght += write(1, "0x", 2);
	lenght += ft_print_hexa(pointer, "0123456789abcdef");
	return (lenght);
}
