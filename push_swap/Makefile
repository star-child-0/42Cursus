PUSH_SWAP_FILES = 

PUSH_SWAP_FILES_BONUS = 

LIBFT_FILES = libft/*.c

LIBFT = libft/libft.a
#------------------------------------------------------------------------------------------------------------------------
OBJECTS=$(FILES:.c=.o)

OBJECTS_BONUS=$(FILES_BONUS:.c=.o)

LIBFT_OBJECTS=$(LIBFT_FILES:.c=.o)
#------------------------------------------------------------------------------------------------------------------------
CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCHIVE = ar -rsv

NAME = push_swap.a
#------------------------------------------------------------------------------------------------------------------------
all: ${NAME}

${NAME}: libft
	${CC} ${CFLAGS} -c ${FILES}
	${ARCHIVE} push_swap.a ${OBJECTS}

bonus:
	${CC} ${CFLAGS} -c ${FILES_BONUS}
	${ARCHIVE} push_swap.a ${OBJECTS_BONUS}

libft:
	make -C libft

clean:
	rm -f ${OBJECTS}
	make -C libft clean

fclean: clean
	rm -f ${NAME} ${LIBFT}
	
re:	fclean all

.PHONY: all clean fclean re
