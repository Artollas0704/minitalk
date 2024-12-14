/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:15:42 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/14 18:05:15 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (argc != 3)
	{
		ft_putstr_fd("Error, input 3 arguments\n", 2);
		return (1);
	}
	else
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		if (!verify_pid(argv[1], argv[2]))
			return (1);
	}
	return (0);
}

int	verify_pid(char *pid, char *str)
{
	int		pid_int;
	int		i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			handle_error("Error pid is not a number");
		i++;
	}
	pid_int = ft_atoi(pid);
	if (pid_int < 1)
		handle_error("Pid does not exist.");
	if (kill(pid_int, 0) == -1)
		handle_error("Pid does not exist.");
	send_str(pid_int, str);
	return (1);
}

void	send_str(int pid, char *message)
{
	unsigned int		i;
	int					j;
	char				c;

	i = 0;
	while (i < ft_strlen(message) + 1)
	{
		c = message[i];
		j = 0;
		while (j < 8)
		{
			send_sig(c, pid);
			c >>= 1;
			j++;
			usleep(500000);
		}
		i++;
	}
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR2)
	{
		ft_printf("Signal received\n");
		exit (1);
	}
}

void	handle_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}
