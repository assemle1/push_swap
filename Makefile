# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astalha <astalha@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 23:42:01 by astalha           #+#    #+#              #
#    Updated: 2022/12/23 16:40:34 by astalha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isdigit.c ft_putstr_fd.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_substr.c linkedlist.c push_swap.c utils1.c
	
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
AR				= ar rc
FLAGS			= -Wall -Wextra -Werror
NAME			= push_swap.a

.PHONY: all clean bonus fclean re

$(NAME): $(OBJS) 
	$(AR) $(NAME) $(OBJS)

all: $(NAME) 
	
%.o: %.c push_swap.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
	 