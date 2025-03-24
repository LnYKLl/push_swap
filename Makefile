# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:03:58 by lkiloul           #+#    #+#              #
#    Updated: 2025/03/24 09:20:54 by lkiloul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBS_DIR = libs
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES = main.c\
			push.c\
			rotate.c\
			reverse_rotate.c\
			swap.c\
			free.c\
			turk.c\
			tiny_sort.c\
			stack_utils.c\
			stack_init.c\
			push_swap_init.c

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INCLUDES = -I$(INC_DIR) -Imlx -I$(LIBFT_INC_DIR)

LIBS = -L$(LIBFT_DIR) -lft

all: $(LIBS) $(NAME)

$(LIBS):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(LIBFT)