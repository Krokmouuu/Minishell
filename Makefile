# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleroy <bleroy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 16:53:35 by bleroy            #+#    #+#              #
#    Updated: 2022/04/29 18:58:12 by bleroy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

SRCS = Core/minishell.c \
	   Parse/lexing.c \
	   Core/prompt.c \
	   Parse/splitcmd.c \
	   Helpers/helpers.c \
	   Helpers/helpers2.c \
	   Utils/ft_strjoin.c \
	   Utils/ft_strnstr.c \
	   Utils/ft_strlen.c \
	   Utils/ft_calloc.c \
	   Utils/ft_strdup.c \
	   Utils/ft_strdup_len.c \
	   Utils/ft_substr.c \
	   Utils/ft_split.c \
	   Utils/ft_strtrim.c \
	   Utils/ft_strcmp.c \
	   Utils/list_utils.c \
	   Utils/list_free.c \
	   Execution/exec_cmd.c \
	   Builtins/builtins.c \
	   Builtins/builtin_cd.c \
	   Builtins/builtin_pwd.c \
	   Builtins/builtin_env.c \
	   Builtins/builtin_list_env.c \
	   Builtins/builtin_export.c \
	   Builtins/builtin_unset.c \
	   Builtins/builtin_echo.c \
	   Builtins/builtin_utils_echo.c \

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = @cc

CFLAGS = -Werror -Wall -Wextra
RM = @rm -f

all: ${NAME}

${NAME}: ${OBJS}
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours.${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours.${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}10% ${_UNDER}${_IGREEN}##${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours..${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}20% ${_UNDER}${_IGREEN}##${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours..${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}21% ${_UNDER}${_IGREEN}###${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours..${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}25% ${_UNDER}${_IGREEN}####${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours..${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}30% ${_UNDER}${_IGREEN}######${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours...${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}42% ${_UNDER}${_IGREEN}########${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours...${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}50% ${_UNDER}${_IGREEN}###########${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours.${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}60% ${_UNDER}${_IGREEN}############${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours. 👀${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}69% ${_UNDER}${_IGREEN}############${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours.${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}70% ${_UNDER}${_IGREEN}##############${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours.${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}75% ${_UNDER}${_IGREEN}##############${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours..${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}80% ${_UNDER}${_IGREEN}################${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}Compilation en cours...${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}90% ${_UNDER}${_IGREEN}##################${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}100%${_UNDER}${_IGREEN}####################${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}STOP${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}112%${_UNDER}${_IRED}#################### ${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}STOOOOP${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}133%${_UNDER}${_IRED}####################      ${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}STOOOOOOOOP${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}205%${_UNDER}${_IRED}####################                         ${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}STOOOOOOOOP${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}256%${_UNDER}${_IRED}####################                                    ${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}${_IGREY}STOOOOOOOOP${_END}"
		@echo "${_BOLD}${_UNDER}${_IGREY}${_UNDER}${_IRED}👹 NYAHAHAHA ####################           👺                         👹             💥                  ${_END}"
		@sleep .1
		@clear
		@echo "${_BOLD}${_UNDER}✨ Compilation terminée sans AUCUN problème ✨${_END}"
		$(CC) $(OBJS) $(CFLAGS) -l readline -o $(NAME)

clean :
		${RM} ${OBJS}
		
fclean: clean
		${RM} ${NAME}

vroom:
		@echo "🐢                      🚗💨"
		@sleep .1
		@clear
		@echo "🐢                     🚗💨"
		@sleep .1
		@clear
		@echo "🐢                    🚗💨"
		@sleep .1
		@clear
		@echo "🐢                   🚗💨"
		@sleep .1
		@clear
		@echo "🐢                  🚗💨"
		@sleep .1
		@clear
		@echo "🐢                 🚗💨"
		@sleep .1
		@clear
		@echo "🐢                🚗💨"
		@sleep .1
		@clear
		@echo "🐢               🚗💨"
		@sleep .1
		@clear
		@echo "🐢              🚗💨"
		@sleep .1
		@clear
		@echo "🐢             🚗💨"
		@sleep .1
		@clear
		@echo "🐢            🚗💨"
		@sleep .1
		@clear
		@echo "🐢           🚗💨"
		@sleep .1
		@clear
		@echo "🐢          🚗💨"
		@echo "🙉 AT          "
		@sleep .15
		@clear
		@echo "🐢         🚗💨"
		@echo "🙉 ATTE       "
		@sleep .15
		@clear
		@echo "🐢        🚗💨"
		@echo "🙉 ATTENTIO   "
		@sleep .15
		@clear
		@echo "🐢       🚗💨"
		@echo "🙉 ATTENTION TO   "
		@sleep .15
		@clear
		@echo "🐢      🚗💨"
		@echo "🙉 ATTENTION TORTU   "
		@sleep .15
		@clear
		@echo "🐢     🚗💨"
		@echo "🙉 ATTENTION TORTUGA !!"
		@sleep .15
		@clear
		@echo "🐢 🛡 🚗💨"
		@echo "🙉 ATTENTION TORTUGA !!"
		@sleep .15
		@clear
		@echo "🐢 🛡🚗💨"
		@echo "🙉 ATTENTION TORTUGA !!"
		@sleep .15
		@clear
		@echo "🐢 🛡💥💨"
		@echo "🙉 OH"
		@sleep .15
		@clear
		@echo "🐢 🛡💥"
		@echo "🙈 OH NON !!"
		@sleep .15
		@clear
		@echo "🐢 🛡"
		@echo "🙈 OH NON !!"
		@sleep .15
		@clear
		@echo "🐢 HEHE"
		@echo "🙈 ..."
		@sleep .15
		@clear
		@echo "🐢 HEHEHE"
		@echo "🙈 ..."
		@sleep .15
		@clear
		@echo "🐢 HEHEHE"
		@echo "🙊 MAIS ??!!"
		@sleep .25
		@clear
		@echo "🐢 HEUREU"
		@echo "🙊 MAIS ??!!"
		@sleep .15
		@clear
		@echo "🐢 HEUREUSEMENT"
		@echo "🙊 ..."
		@sleep .15
		@clear
		@echo "🐢 HEUREUSEMENT QUE JE"
		@echo "🙊 ..."
		@sleep .15
		@clear
		@echo "🐢 HEUREUSEMENT QUE JE PROTÈGE"
		@echo "🙊 ..."
		@sleep .15
		@clear
		@echo "🐢 HEUREUSEMENT QUE JE PROTÈGE MES MALLOCS"
		@echo "🙊 ..."
		@sleep 2.5
		@clear
		@echo "🐢 HAHAHAHAHA 🤣"
		@echo "🐒 HIhiHiHihihIi 😂 MDRRRRR"
		@sleep .5
		@clear
		@echo "🐢 HAHAHAHA 🤣"
		@echo "🐒 HIhiHiHihihIiHIhi 😂 MDRRRRR"
		@sleep .5
		@clear
		@echo "🐢 HAHAHAHAHAHAHA 🤣"
		@echo "🐒 HIhiHiHihihohohIiHIhi 😂 MDRRRRR"
		@sleep 1
		@clear
		@echo "🐢 HAHAHAHAHAHAHA 🤣"
		@echo "🐒 HIhiHiHihihohohIiHIhi 😂 MDRRRRR"
		@echo "🦅 ET BEH... "
		@sleep .5
		@clear
		@echo "🐢 ...."
		@echo "🐒 ...."
		@echo "🦅 ET BEH... "
		@sleep 1
		@clear
		@echo "🐢 ...."
		@echo "🐒 ...."
		@echo "🦅 ÇA VOLE PAS HAUT TOUT ... "
		@sleep .25
		@clear
		@echo "🐢 ..."
		@echo "🐒 ..."
		@echo "🦅 ÇA VOLE PAS HAUT TOUT ÇA... (je vole haut car je suis un aigle) "
		@sleep 2.5
		@clear
		@echo "🐢 HAHAHAHAHAHAHA 🤣"
		@echo "🐒 ihiihhihi MDRRR "
		@echo "🦅 XDDDDDDDDDD"
		@sleep .15
		@clear
		@echo "🐢 HAHAHAHAHAHAHA 🤣"
		@echo "🐒 ihiihhihi MDRRR "
		@echo "🦅 XDDDDDDDDDDDDDDDD"
		@sleep .15
		@clear
		@echo "🐢 HAHAHAHAHAHAHA 🤣"
		@echo "🐒 ihiihhihi MDRRR "
		@echo "🦅 XDDDDDDDDDDDDDDDDDD"
		@sleep 1
		@clear
		@echo "🐢 ... "
		@echo "🐒 ... "
		@echo "🦅 ..."
		@echo "🥖 HEY VOUS LÀ !!"
		@sleep 2
		@clear
		@echo "🐢 ..."
		@echo "🐒 ..."
		@echo "🦅 ..."
		@echo "🥖 ÇA MANGE PAS DE PAIN ^^ !!"
		@sleep 2
		@clear
		@echo "🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ÇA MANGE PAS DE PAIN ^^ !!"
		@sleep 1
		@clear
		@echo "🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "   🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "      🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "         🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "            🐢🐒🦅"
		@echo " "
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "               🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 ..."
		@sleep .2
		@clear
		@echo "                   🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                       🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                           🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                 🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                       🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                            🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                                 🐢🐒🦅"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                                  🐢🐒"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                                   🐢"
		@echo ""
		@echo " "
		@echo "🥖 hey les copains"
		@sleep .2
		@clear
		@echo "                                                    "
		@echo ""
		@echo " "
		@echo "🥖 ..."
		@sleep 1
		@clear
		@echo "                                                    "
		@echo ""
		@echo " "
		@echo "🥖 et beh"
		@sleep 2
		@clear
		@echo "👮                                                    "
		@echo ""
		@echo " "
		@echo "🥖 bonjour monsieur l'agent"
		@sleep 2
		@clear
		@echo "👮 bonjour monsieur le pain                                    "
		@echo ""
		@echo " "
		@echo "🥖 ..."
		@sleep 2
		@clear
		@echo "👮 vous ne seriez pas perdu par hasard  (pain perdu)            "
		@echo ""
		@echo " "
		@echo "🥖 ..."
		@sleep 4
		@clear
		@echo "👮 mdr bon aller vous etes en état d'arrestation pour non-rire a ma blague cool"
		@echo ""
		@echo " "
		@echo "🥖 ..."
		@sleep 3
		@clear
		@echo "👮             "
		@echo ""
		@echo "🥖 NON MONSIEUR "
		@echo ""
		@sleep 1
		@clear
		@echo "👮 pas de chichi svp"
		@echo ""
		@echo "🥖 svpliz  "
		@echo ""
		@sleep 1
		@clear
		@echo "👮 pas de chichi svp"
		@echo "🥖 svpliz  "
		@echo ""
		@echo ""
		@sleep 1
		@clear
		@echo "👮 🥖🚔"
		@echo " on rentre dans le vehicule dans le calme  "
		@echo ""
		@echo ""
		@sleep 1
		@clear
		@echo "👮 🚔"
		@echo " on rentre dans le vehicule dans le calme  "
		@echo ""
		@echo ""
		@sleep 1
		@clear
		@echo "🚔"
		@echo " la racaille ça dégage  "
		@echo ""
		@echo ""
		@sleep .5
		@clear
		@echo "🚓"
		@echo " "
		@echo ""
		@echo ""
		@sleep .5
		@clear

re :    fclean all

.PHONY: all clean fclean re