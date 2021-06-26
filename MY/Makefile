# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/06/26 02:19:53 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= phlsphrs

HEADER		= ft_philosophers.h

SRC 		= 	main.c \
				prsr.c \
				utils.c \

OBJS		= ${SRC:.c=.o}

GCC			= gcc

CFLAGS		= -g -pthread -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

.c.o:		
				${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} ${HEADER}
				${GCC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}

re:		fclean all