# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 16:48:42 by aghergut          #+#    #+#              #
#    Updated: 2025/02/05 13:14:34 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY = \033[0;90m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET_COLOR = \033[0m

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVERB_SRC = server_bonus.c
CLIENTB_SRC = client_bonus.c

LIBFT_FLAGS = -Llibft -lft
LIBFT_MAKE = make -s -C libft > /dev/null 2>&1
LIBFT_FCLEAN = make -s -C libft fclean > /dev/null 2>&1

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVERB_OBJ = $(SERVERB_SRC:.c=.o)
CLIENTB_OBJ = $(CLIENTB_SRC:.c=.o)

all: $(SERVER) $(CLIENT) 

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(SERVER): $(SERVER_OBJ)
	@echo "$(GRAY)Compiling libft...$(RESET_COLOR)"
	@$(LIBFT_MAKE)
	@echo "$(CYAN)Linking...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(SERVER_OBJ) $(LIBFT_FLAGS) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	@$(COMPILER) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT_FLAGS) -o $(CLIENT)
	@echo "$(WHITE)Minitalk compiled successfully!$(RESET_COLOR)"

bonus: fclean $(SERVERB_OBJ) $(CLIENTB_OBJ)
	@echo "$(GRAY)Compiling libft...$(RESET_COLOR)"
	@$(LIBFT_MAKE)
	@echo "$(CYAN)Linking bonus...$(RESET_COLOR)"
	@$(COMPILER) $(CFLAGS) $(SERVERB_OBJ) $(LIBFT_FLAGS) -o $(SERVER)
	@$(COMPILER) $(CFLAGS) $(CLIENTB_OBJ) $(LIBFT_FLAGS) -o $(CLIENT)
	@echo "$(WHITE)Minitalk's bonus compiled successfully!$(RESET_COLOR)"

clean:
	@if [ -f "$(SERVER_OBJ)" ]; then rm -f "$(SERVER_OBJ)"; fi
	@if [ -f "$(CLIENT_OBJ)" ]; then rm -f "$(CLIENT_OBJ)"; fi
	@if [ -f "$(SERVERB_OBJ)" ]; then rm -f "$(SERVERB_OBJ)"; fi
	@if [ -f "$(CLIENTB_OBJ)" ]; then rm -f "$(CLIENTB_OBJ)"; fi
	@echo "Objects removed!"
	@$(LIBFT_FCLEAN)
	
fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Minitalk removed!"

re: fclean all

.PHONY: all bonus clean fclean re