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

void ft_handler(int signal, siginfo_t *info, void *context)
{
	kill(info->si_pid, SIGUSR1);
}

void ft_send_char(int pid, char c)
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
	t_sigaction act;
	sigset_t	sa_mask;

	sigemptyset(&sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_mask = sa_mask;
	act.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc != 3 || ft_check_pid(argv[1]))
		exit(1);
	if (ft_atoi(argv[1]) == 0)
		exit(1);
	ft_send_message(argv[2]);
}
