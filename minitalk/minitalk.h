/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:42:15 by oburato           #+#    #+#             */
/*   Updated: 2022/11/17 04:06:55 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct sigaction t_sigaction;

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

// lib put
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

// lib num
int		ft_check_pid(char *arg);

// atoi
int	ft_atoi(const char *str);

// str c
char	*ft_straddc(char *str, char c);
size_t	ft_strlen(const char *s);

#endif
