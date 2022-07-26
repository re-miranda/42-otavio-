/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:59:56 by oburato           #+#    #+#             */
/*   Updated: 2022/07/26 04:07:28 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../main.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_print_hexa(size_t number, const char *base);
int		ft_print_pointer(size_t pointer);
int		ft_print_unsigned_number(unsigned int number);
int		ft_printf(const char *str, ...);
int		ft_check_flag(const char flag, va_list args);
int		ft_print_string(char *str);
int		ft_print_number(int number);
char	*ft_printf_strchr(const char *s, int c);

#endif
