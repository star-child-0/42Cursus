FILES = main.c utils.c utils2.c utils3.c sorting_algorithms.c \
	operations_p.c operations_s.c operations_r.c

LIBFT = libft/libft.a

OBJECTS = $(FILES:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	clear
clean:
	make clean -C libft
	$(RM) $(OBJECTS)
	clear

fclean: clean
	make fclean -C libft
	$(RM) $(NAME) $(OBJECTS)
	clear

re: fclean all

.PHONY:	all clean fclean re
