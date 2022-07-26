/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 01:26:47 by oburato           #+#    #+#             */
/*   Updated: 2022/07/26 00:52:48 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		lenght;

	index = 0;
	lenght = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[index])
	{
		if (str[index] == '%' && ft_printf_strchr("cspdiuxX%", str[index + 1]))
		{
			lenght += ft_check_flag(str[index + 1], args);
			index++;
		}
		else
			lenght += write(1, &str[index], 1);
		index++;
	}
	va_end(args);
	return (lenght);
}

int	ft_check_flag(const char flag, va_list args)
{
	int		lenght;
	size_t	aux;

	lenght = 0;
	aux = 0;
	if (flag == 'c')
	{
		aux = va_arg(args, int);
		lenght += write(1, &aux, 1);
	}
	else if (flag == '%')
		lenght += write(1, "%", 1);
	else if (flag == 's')
		lenght += ft_print_string(va_arg(args, char *));
	else if (flag == 'p')
		lenght += ft_print_pointer(va_arg(args, size_t));
	else if (flag == 'd' || flag == 'i')
		lenght += ft_print_number(va_arg(args, int));
	else if (flag == 'u')
		lenght += ft_print_unsigned_number(va_arg(args, unsigned int));
	else if (flag == 'x')
		lenght += ft_print_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (flag == 'X')
		lenght += ft_print_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (lenght);
}
