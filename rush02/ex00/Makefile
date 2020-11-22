SRCS		= main.c dict.c file_operations.c ft_strncpy.c ft_split.c ft_strcmp.c convert.c ft_strlen.c ft_putstr.c data_operations.c ft_list_push_back.c ft_create_list_elem.c convert_functions.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

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
