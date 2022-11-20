/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:23:30 by oburato           #+#    #+#             */
/*   Updated: 2022/11/17 03:55:23 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pid;

void	ft_send_char(unsigned int str_index, char *c)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if (*c & (0b10000000 >> bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit++;
		usleep(800);
	}
	(void)str_index;
}

void	ft_send_message(char *str)
{
	ft_striteri(str, ft_send_char);
}

int	main(int argc, char ** argv)
{
	if (argc != 3 || ft_check_pid(argv[1], &pid))
		exit(1);
	ft_send_message(argv[2]);
}
