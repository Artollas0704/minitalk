# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aralves- < aralves-@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 18:57:43 by aralves-          #+#    #+#              #
#    Updated: 2024/12/10 22:29:04 by aralves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME_SERVER = server
NAME_CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=gnu17
LIBCREATE = ar rc
RM = rm -rf
LIBFT_DIR = libft

SRCS_SERVER = server.c\

SRCS_CLIENT = minitalk.c\

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME_SERVER): $(OBJS_SERVER)
		make -C $(LIBFT_DIR) all
		cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS_SERVER) -L. -lft -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
		make -C $(LIBFT_DIR) all
		cp libft/libft.a .
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -L. -lft -o $(NAME_CLIENT)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: all

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) libft.a
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re