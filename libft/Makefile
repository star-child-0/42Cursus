FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstdelone.c ft_lstclear.c ft_lstadd_back.c \
	ft_lstiter.c ft_lstmap.c \
	ft_printf.c ft_putchar.c ft_put_pointer.c \
	ft_nbrlen.c ft_putnbr.c ft_putstr.c ft_putnbr_hex.c \
	ft_putunsign_nbr.c get_next_line.c \
	ft_atol.c ft_atof.c

OBJECTS = ${FILES:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARCHIVE = ar -rsv

REMOVE = rm -f

NAME = libft.a

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -c ${FILES}
	${ARCHIVE} libft.a ${OBJECTS}

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean re