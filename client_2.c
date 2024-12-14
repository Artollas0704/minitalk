/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:58:26 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/14 18:04:10 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_sig(char c, int pid)
{
	if (c & 1)
	{
		if (kill(pid, SIGUSR1) == -1)
			handle_error("Error, Signal not sent.");
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			handle_error("Error, Signal not sent.");
	}
}
