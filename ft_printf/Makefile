FILES = ft_printf.c ft_putchar.c ft_put_pointer.c ft_nbrlen.c \
ft_putnbr.c ft_putstr.c ft_putnbr_hex.c ft_putunsign_nbr.c
OBJECTS=$(FILES:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror 
NAME=libftprintf.a

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -c ${FILES}
	ar -rsv libftprintf.a ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}
	
re:	fclean all

.PHONY: all clean fclean re
