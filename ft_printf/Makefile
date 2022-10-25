FILES = 
FILES_BONUS = 
OBJECTS=$(FILES:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror 
NAME=libftprintf.a

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -c ${FILES}
	ar -rsv libft.a ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}
	
re:	fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus
