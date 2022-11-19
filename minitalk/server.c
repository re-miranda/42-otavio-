/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:23:30 by oburato           #+#    #+#             */
/*   Updated: 2022/11/17 04:13:52 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void ft_handler(int signal)
{
	static char	c = 0b11111111;
	static int	bits = 0;
	static char	*msg = 0;

	if (signal == SIGUSR1)
		c |= 0b10000000 >> bits;
	else if (signal == SIGUSR2)
		c ^= 0b10000000 >> bits;
	if (++bits == 8)
	{
		if (c)
			msg = ft_straddc(msg, c);
		else
		{
			write(1, msg, ft_strlen(msg));
		}
		bits = 0;
		c = 0b11111111;
	}
}

int main(void)
{
	t_sigaction act;
	sigset_t	sa_mask;

	sigemptyset(&sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_mask = sa_mask;
	act.sa_handler = ft_handler;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while(1)
		pause();
}
