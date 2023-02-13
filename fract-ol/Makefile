FILES = main.c 

LIBFT = ../libft/libft.a

OBJECTS = $(FILES:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = fractol

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C ../libft
	make all -C ./minilibx-linux
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	clear

clean:
	make clean -C ../libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJECTS)
	clear

fclean: clean
	make fclean -C ../libft
	$(RM) $(NAME) $(OBJECTS)
	clear

re: fclean all

.PHONY:	all clean fclean re
