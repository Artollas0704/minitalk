/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aralves- < aralves-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:49:11 by aralves-          #+#    #+#             */
/*   Updated: 2024/12/10 22:32:11 by aralves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "./libft/ft_printf.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <signal.h>

int			main(void);
int			verify_pid(char *pid, char *str);
#endif