SRCS		= main.c t_map.c bruteforce.c ft_putstr.c file_operations.c ft_putchar.c ft_strcpy.c t_square.c ft_split.c ft_atoi.c ft_strlen.c stdin_operations.c validation.c ft_puterrstr.c

OBJS		= ${SRCS:.c=.o}

NAME		= BSQ

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:	
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
