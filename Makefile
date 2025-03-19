# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 12:14:59 by utente            #+#    #+#              #
#    Updated: 2025/03/19 01:19:52 by lkiloul          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
INCDIR = includes
CFLAGS = -Wall -Wextra -Werror -g -I$(INCDIR)
MAKE_LIB = ar -rcs

SRCDIR = srcs
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re