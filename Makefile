# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouab <ytouab@student.42abudhabi.ae>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 16:07:37 by ytouab            #+#    #+#              #
#    Updated: 2022/03/05 03:50:11 by ytouab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

OBJS		= ${SRC:.c=.o}

WHITE		=	"\033[0m"
RED			=	"\033[0;31m"
GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"

RM			=	rm -f

GCCF		=	gcc -Wall -Wextra -Werror

MLX			=	-Lmlx -lmlx -framework OpenGL -framework AppKit





SRC			=	so_long.c \
				srcs/so_long_utils.c \
				srcs/so_long_utils2.c \
				srcs/map_checker.c \
				srcs/helper_functions.c



.c.o:
		@${GCCF} -c $< -o ${<:.c=.o}


$(NAME):	${OBJS}
		@${GCCF} ${OBJS} ${MLX} -o ${NAME}
		@echo ${GREEN}"Compilation Done ✅"

normal: 	${OBJS}
		@${GCCF} ${OBJS} -o ${NAME}
		@echo ${GREEN}"Compilation Done ✅"


all:	${NAME}

clean:
		@${RM} ${OBJS}
		@echo ${RED}"Object Files Deleted ✅"${WHITE}

fclean:	clean
		@${RM} ${NAME}
		@echo ${RED}"Executable File Deleted ✅"${WHITE}

re:		fclean all
