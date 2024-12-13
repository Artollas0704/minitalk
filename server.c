/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:36:28 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/13 16:14:54 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdlib.h>
#include <sys/signal.h>
#include <unistd.h>
#include <sys/types.h>

void	get_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit_count;

	(void)context;
	if (!info)
		exit(0);
    if(signum == SIGUSR1)
	{
        c |= (1 << bit_count);
	}
    else if(signum == SIGUSR2)
	{
        c &= ~(1 << bit_count);
	}
	bit_count++;
	if (bit_count == 8)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
		}
		c = 0;
		bit_count = 0;
	}
	kill(info->si_pid, signum);
}

int main(void)
{
	struct sigaction	sa;
	
	get_pid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
