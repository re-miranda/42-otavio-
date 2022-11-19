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

void ft_send_char(int pid, char c)
{
	int bit;

	bit = 0;
	while (bit <= 8)
	{
		if (c & 0b10000000 >> bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(800);
	}
}

void ft_send_message(int pid, char *str)
{
	int bit;

	bit = 0;
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
	ft_send_char(pid, *str);
}

int main(int argc, char ** argv)
{
	if (argc != 3 || ft_check_pid(argv[1]))
		exit(1);
	if (ft_atoi(argv[1]) == 0)
		exit(1);
	ft_send_message(ft_atoi(argv[1]), argv[2]);
}
