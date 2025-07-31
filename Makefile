# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 15:51:41 by framiran          #+#    #+#              #
#    Updated: 2025/07/21 17:41:04 by framiran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Default rule: build everything
all: $(NAME)

# Rule to build the executable
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -g -o $(NAME)

# Compile source files to object files (only if changed)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files and libft objects
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything, including the executable and libft library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything from scratch
re: fclean all
