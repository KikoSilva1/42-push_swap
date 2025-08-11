# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framiran <framiran@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/21 15:51:41 by framiran          #+#    #+#              #
#    Updated: 2025/08/08 12:26:35 by framiran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -I. -ILibft

LIBFT_DIR = Libft
LIBFT     = $(LIBFT_DIR)/libft.a

SRCS = src/basic_operations.c \
       src/general_helpers.c \
       src/general_sort_helpers.c \
       src/initializers.c \
       src/initializers_helpers.c \
       src/main.c \
       src/memory_managers.c \
       src/parser.c \
       src/parser_helpers.c \
       src/radix_helpers.c \
       src/simple_sorts.c

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
