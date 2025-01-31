# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 14:39:20 by rchavez           #+#    #+#              #
#    Updated: 2024/04/23 11:52:14 by rchavez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = Main.c Main_utils.c list_utils.c rules.c turk_sort.c turk_utils_0.c \
		turk_utils_1.c turk_utils_2.c ft_split.c ft_parse.c

OFILES = $(CFILES:.c=.o)

all : $(NAME)

$(NAME) : $(CFILES)
	$(CC) $(CFLAGS) -o $@ $^

clean : 
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

PHONY : all clean fclean re