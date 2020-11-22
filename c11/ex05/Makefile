# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelderbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 11:22:42 by lelderbe          #+#    #+#              #
#    Updated: 2020/09/23 15:30:10 by lelderbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ft_atoi.c ft_operations.c ft_putnbr.c ft_putstr.c

OBJS		= ${SRCS:.c=.o}

NAME		= do-op

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
