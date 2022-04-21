# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:53:35 by bleroy            #+#    #+#              #
#    Updated: 2022/04/21 19:44:50 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = minishell.c \
	   lexing.c \
	   env.c \
	   prompt.c \
	   splitcmd.c \
	   helpers.c \
	   helpers2.c \
	   Utils/ft_strnstr.c \
	   Utils/ft_strlen.c \
	   Utils/ft_calloc.c \
	   Utils/ft_strdup.c \
	   Utils/ft_substr.c \
	   Utils/ft_split.c \
	   Utils/ft_strtrim.c \
	   Utils/ft_strlcpy.c \
	   Utils/ft_strlcat.c \
	   Utils/ft_strjoin.c \
	   list_utils.c \
	   list_free.c \
	   Builtins/builtins.c \
	   Builtins/builtin_echo.c \
	   Builtins/builtin_pwd.c \
	   Builtins/builtin_env.c \
	   Builtins/builtin_export.c \


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