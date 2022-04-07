# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:53:35 by bleroy            #+#    #+#              #
#    Updated: 2022/04/07 17:32:21 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c \
	   Utils/ft_strstr.c \
	   Utils/ft_split.c \
	   Utils/ft_strlen.c \
	   lexing.c \
	   parsing.c \

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = cc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

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