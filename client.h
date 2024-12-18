/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- <aralves-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 19:28:02 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/14 18:05:30 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <limits.h>
# include <signal.h>

int			main(int argc, char	**argv);
int			verify_pid(char *pid, char *str);
void		send_str(int pid, char *message);
void		signal_handler(int signum, siginfo_t *info, void *context);
void		send_sig(char c, int pid);
void		handle_error(char *str);
#endif