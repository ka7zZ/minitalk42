# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 16:48:42 by aghergut          #+#    #+#              #
#    Updated: 2024/12/20 12:17:08 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SRCS = server.c client.c
SRCSB = server_bonus.c client_bonus.c

OBJECTS = $(SRCS:.c=.o)
OBJECTS_BONUS = $(SRCSB:.c=.o)


all: server client

server: libft
	@$(CC) $(CFLAGS) $(SERVER) -o server -Llibft -lft
	@echo "Server compiled"
	
client: libft
	@$(CC) $(CFLAGS) $(CLIENT) -o client -Llibft -lft
	@echo "Client compiled"

server_bonus: libft
	@$(CC) $(CFLAGS) $(SERVER_BONUS) -o server_bonus -Llibft -lft

client_bonus: libft
	@$(CC) $(CFLAGS) $(CLIENT_BONUS) -o client_bonus -Llibft -lft

bonus: server_bonus client_bonus
	@rm -f server client
	@echo "Bonus compiled"

libft:
	@make -C libft

clean:
	@rm -f $(OBJECTS)
	@echo "Objects removed"
	@rm -f $(OBJECTS_BONUS)
	@echo "Bonus objects removed"
	@make -C libft fclean
	
fclean: clean
	@rm -f server client libft/libft.a server_bonus client_bonus

re: fclean all

.PHONY: all libft bonus clean fclean re
