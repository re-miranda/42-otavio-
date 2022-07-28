/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:51:14 by oburato           #+#    #+#             */
/*   Updated: 2022/07/28 02:54:12 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// int main(int argc, char *argv[])
int main(void)
{
	while (true)
		ft_printf("%s", get_next_line(0));
	return (0);
}
