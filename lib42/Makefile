# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aghergut <aghergut@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 13:11:03 by aghergut          #+#    #+#              #
#    Updated: 2024/10/17 14:34:45 by aghergut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Werror -Wextra 

NAME = libft.a

# Define folders for different parts of the library
CHANGECHAR_FOLDER = changechar/
CHECKCHAR_FOLDER = checkchar/
STRTOINT_FOLDER = strtoint/
GET_NEXT_LINE_FOLDER = get_next_line/
STRINGS_FOLDER = strings/
MEMORY_FOLDER = memory/
PUTS_FOLDER = puts/
LISTS_FOLDER = lists/
FTPRINTF_FOLDER = ft_printf/

# Source files for each module
SRCS1 = $(CHANGECHAR_FOLDER)ft_tolower.c $(CHANGECHAR_FOLDER)ft_toupper.c
SRCS2 = $(CHECKCHAR_FOLDER)ft_isalnum.c $(CHECKCHAR_FOLDER)ft_isascii.c \
	  $(CHECKCHAR_FOLDER)ft_isalpha.c $(CHECKCHAR_FOLDER)ft_isdigit.c \
	  $(CHECKCHAR_FOLDER)ft_isprint.c
SRCS3 = $(STRTOINT_FOLDER)ft_atoi.c $(STRTOINT_FOLDER)ft_itoa.c
SRCS4 = $(GET_NEXT_LINE_FOLDER)get_next_line.c
SRCS5 = $(STRINGS_FOLDER)ft_strchr.c $(STRINGS_FOLDER)ft_strlcat.c \
	  $(STRINGS_FOLDER)ft_strlcpy.c $(STRINGS_FOLDER)ft_strlen.c \
	  $(STRINGS_FOLDER)ft_strncmp.c $(STRINGS_FOLDER)ft_strnstr.c \
	  $(STRINGS_FOLDER)ft_strrchr.c $(STRINGS_FOLDER)ft_strtrim.c \
	  $(STRINGS_FOLDER)ft_substr.c $(STRINGS_FOLDER)ft_strjoin.c \
	  $(STRINGS_FOLDER)ft_split.c $(STRINGS_FOLDER)ft_strdup.c \
	  $(STRINGS_FOLDER)ft_strmapi.c $(STRINGS_FOLDER)ft_strncat.c \
	  $(STRINGS_FOLDER)ft_striteri.c $(STRINGS_FOLDER)ft_calloc.c \
	  $(STRINGS_FOLDER)ft_bzero.c 
SRCS6 = $(MEMORY_FOLDER)ft_memset.c $(MEMORY_FOLDER)ft_memcpy.c \
	  $(MEMORY_FOLDER)ft_memmove.c $(MEMORY_FOLDER)ft_memchr.c \
	  $(MEMORY_FOLDER)ft_memcmp.c
SRCS7 = $(PUTS_FOLDER)ft_putchar_fd.c $(PUTS_FOLDER)ft_putstr_fd.c \
	  $(PUTS_FOLDER)ft_putendl_fd.c $(PUTS_FOLDER)ft_putnbr_fd.c \
	  $(PUTS_FOLDER)ft_putuint.c
SRCS8 = $(LISTS_FOLDER)ft_lstnew.c $(LISTS_FOLDER)ft_lstadd_front.c \
	  $(LISTS_FOLDER)ft_lstsize.c $(LISTS_FOLDER)ft_lstlast.c \
	  $(LISTS_FOLDER)ft_lstadd_back.c $(LISTS_FOLDER)ft_lstdelone.c \
	  $(LISTS_FOLDER)ft_lstclear.c $(LISTS_FOLDER)ft_lstiter.c \
	  $(LISTS_FOLDER)ft_lstmap.c
SRCS9 = $(FTPRINTF_FOLDER)flags/ft_flagadd.c $(FTPRINTF_FOLDER)prints/ft_printchar.c \
	  $(FTPRINTF_FOLDER)flags/ft_flagset.c $(FTPRINTF_FOLDER)prints/ft_printstr.c \
	  $(FTPRINTF_FOLDER)flags/ft_flagalt.c $(FTPRINTF_FOLDER)prints/ft_printint.c \
	  $(FTPRINTF_FOLDER)flags/ft_flagsign.c $(FTPRINTF_FOLDER)prints/ft_printu.c \
	  $(FTPRINTF_FOLDER)flags/ft_flagspace.c $(FTPRINTF_FOLDER)prints/ft_printpxx.c \
	  $(FTPRINTF_FOLDER)utils/ft_fill.c $(FTPRINTF_FOLDER)utils/ft_gethex.c \
	  $(FTPRINTF_FOLDER)utils/ft_memlen.c $(FTPRINTF_FOLDER)utils/ft_numlen.c \
	  $(FTPRINTF_FOLDER)ft_printf.c

# Object directories
OBJS_DIR_CHANGECHAR = $(CHANGECHAR_FOLDER)o_files/
OBJS_DIR_CHECKCHAR = $(CHECKCHAR_FOLDER)o_files/
OBJS_DIR_STRTOINT = $(STRTOINT_FOLDER)o_files/
OBJS_DIR_GET_NEXT_LINE = $(GET_NEXT_LINE_FOLDER)o_files/
OBJS_DIR_STRINGS = $(STRINGS_FOLDER)o_files/
OBJS_DIR_MEMORY = $(MEMORY_FOLDER)o_files/
OBJS_DIR_PUTS = $(PUTS_FOLDER)o_files/
OBJS_DIR_LISTS = $(LISTS_FOLDER)o_files/
OBJS_DIR_FTPRINTF = $(FTPRINTF_FOLDER)o_files/

# Object files with correct paths
OBJS = $(addprefix $(OBJS_DIR_CHANGECHAR), $(notdir $(SRCS1:.c=.o))) \
	$(addprefix $(OBJS_DIR_CHECKCHAR), $(notdir $(SRCS2:.c=.o))) \
	$(addprefix $(OBJS_DIR_STRTOINT), $(notdir $(SRCS3:.c=.o))) \
	$(addprefix $(OBJS_DIR_GET_NEXT_LINE), $(notdir $(SRCS4:.c=.o))) \
	$(addprefix $(OBJS_DIR_STRINGS), $(notdir $(SRCS5:.c=.o))) \
	$(addprefix $(OBJS_DIR_MEMORY), $(notdir $(SRCS6:.c=.o))) \
	$(addprefix $(OBJS_DIR_PUTS), $(notdir $(SRCS7:.c=.o))) \
	$(addprefix $(OBJS_DIR_LISTS), $(notdir $(SRCS8:.c=.o))) \
	$(addprefix $(OBJS_DIR_FTPRINTF), $(notdir $(SRCS9:.c=.o)))

INCLUDES = -I.

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(NAME) created successfully!"

# Create object directories and compile
$(OBJS_DIR_CHANGECHAR)%.o: $(CHANGECHAR_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_CHANGECHAR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_CHECKCHAR)%.o: $(CHECKCHAR_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_CHECKCHAR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_STRTOINT)%.o: $(STRTOINT_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_STRTOINT)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_GET_NEXT_LINE)%.o: $(GET_NEXT_LINE_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_GET_NEXT_LINE)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_STRINGS)%.o: $(STRINGS_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_STRINGS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_MEMORY)%.o: $(MEMORY_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_MEMORY)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_PUTS)%.o: $(PUTS_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_PUTS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_LISTS)%.o: $(LISTS_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_LISTS)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR_FTPRINTF)%.o: $(FTPRINTF_FOLDER)%.c
	@mkdir -p $(OBJS_DIR_FTPRINTF)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule to remove object files
clean:
	rm -Rf */o_files

# Full clean rule
fclean: clean
	rm -f $(NAME)
	

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re