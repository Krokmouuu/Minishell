# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:53:35 by bleroy            #+#    #+#              #
#    Updated: 2022/04/12 14:09:50 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c \
	   Utils/ft_strstr.c \
	   Utils/ft_split.c \
	   Utils/ft_strlen.c \
	   Utils/ft_calloc.c \
	   Utils/ft_strdup.c \
	   Utils/ft_substr.c \
	   Utils/ft_strjoin.c \
	   lexing.c \
	   parsing.c \
	   splitcmd.c \
	   checkcmd.c \

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = cc

CFLAGS = -Werror -Wall -Wextra -g -fsanitize=address

RM = rm -f

all: ${NAME}

${NAME}: ${OBJS}
		$(CC) $(OBJS) $(CFLAGS) -l readline -o $(NAME)

clean :
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re :    fclean all

.PHONY: all clean fclean re