/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libnum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:31:01 by oburato           #+#    #+#             */
/*   Updated: 2022/11/15 21:40:04 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check_pid(char *arg)
{
	while(*arg)
	{
		if (*arg >= '0' && *arg <= '9')
			return (0);
		arg++;
	}
	return (1);
}
