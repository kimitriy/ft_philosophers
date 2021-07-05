# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rburton <rburton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:32:38 by rburton           #+#    #+#              #
#    Updated: 2021/07/06 00:38:25 by rburton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

HEADER		= ft_philosophers.h

SRC 		= 	main.c \
				prsr.c \
				pthreads1.c \
				pthreads2.c \
				monitor.c \
				utils1.c \
				utils2.c \

OBJS		= ${SRC:.c=.o}

GCC			= gcc

# CFLAGS		= -g -pthread -Wall -Wextra -Werror
# CFLAGS		= -g -Wall -Wextra -Werror
CFLAGS		= -Wall -Wextra -Werror

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