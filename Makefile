# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 16:48:42 by aghergut          #+#    #+#              #
#    Updated: 2024/10/17 17:51:57 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

SERVER = server.c
CLIENT = client.c

OBJECTS = $(SERVER:.c=.o) $(CLIENT:.c=.o)

all: server client

server: libft
	@$(CC) $(CFLAGS) $(SERVER) -o server -Llibft -lft
	@echo "Server compiled"
	
client: libft
	@$(CC) $(CFLAGS) $(CLIENT) -o client -Llibft -lft
	@echo "Client compiled"
	
libft:
	@make -C libft

clean:
	@rm -f $(OBJECTS)
	@make -C libft fclean
	
fclean: clean
	@rm -f server client libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re