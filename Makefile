# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 23:42:01 by astalha           #+#    #+#              #
#    Updated: 2022/12/27 22:08:33 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isdigit.c ft_putstr_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_substr.c linkedlist.c push_swap.c utils1.c
	
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
FLAGS			= -Wall -Wextra -Werror
NAME			= push_swap

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS) 
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME) 
	
%.o: %.c push_swap.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
	 