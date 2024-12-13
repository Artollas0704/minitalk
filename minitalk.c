/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- < aralves-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:15:42 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/10 22:09:18 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putstr_fd("Error, input 3 arguments\n", 2);
		return (0);
	}
	else
	{
		if (!verify_pid(argv[1], argv[2]))
			return (0);
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
		{
			ft_putstr_fd("Error, pid is not a number\n", 2);
			return (0);
		}
		i++;
	}
	pid_int = ft_atoi(pid);
	if (pid_int < 1)
	{
		ft_putstr_fd("Error, pid is out of range\n", 2);
		return (0);
	}
	if (kill(pid_int, 0) == -1)
	{
		ft_putstr_fd("Error, pid does not exist\n", 2);
		return (0);
	}
	if (!str)
		return (0);
	send_str(pid_int, str);
	return (1);
}
void send_str(int pid, char *message)
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
			if (c & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
				{
					ft_putstr_fd("Error, signal not sent\n", 2);
					return ;
				}
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
				{
					ft_putstr_fd("Error, signal not sent\n", 2);
					return ;
				}
			}
			c >>= 1;
			j++;
			usleep(500000);
		}
		i++;
	}
}