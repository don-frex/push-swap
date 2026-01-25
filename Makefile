# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaber <asaber@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 14:14:27 by asaber            #+#    #+#              #
#    Updated: 2023/03/28 18:08:36 by asaber           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c check_errors.c actions.c check_acending.c ft_sort.c ft_split.c linked_data.c postion.c

SRCB = check_errors.c actions.c check_acending.c ft_sort.c ft_split.c linked_data.c postion.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/checker.c

OBJS = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

bonus: $(BONUS)

$(BONUS): $(SRCB)
	$(CC) $(CFLAGS) $^ -o $(BONUS)

$(NAME) : $(SRC)
	$(CC) $(CFLAGS) $^ -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean