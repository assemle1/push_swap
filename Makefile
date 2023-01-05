# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 23:42:01 by astalha           #+#    #+#              #
#    Updated: 2023/01/05 21:21:03 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	actions.c check.c ft_split.c ft_strjoin.c libft1.c libft2.c linkedlist.c push_swap.c rules1.c rules2.c movs.c utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c
	
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -g
NAME			= push_swap

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME) 
	
%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
	 