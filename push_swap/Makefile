FILES = main.c sorting_algorithms.c \
	utils.c utils2.c utils3.c utils4.c \
	operations_p.c operations_s.c operations_r.c operations_r2.c
	
BONUS_FILES = checker.c utils_checker.c utils_checker2.c

LIBFT = ../libft/libft.a

OBJECTS = $(FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_FILES:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)

bonus: all $(BONUS_NAME)

$(NAME): $(OBJECTS)
	make -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

$(BONUS_NAME): $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS) $(LIBFT)
	clear

clean:
	make clean -C ../libft
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	clear

fclean: clean
	make fclean -C ../libft
	$(RM) $(NAME) $(BONUS_NAME) $(OBJECTS) $(BONUS_OBJECTS)
	clear

re: fclean bonus

.PHONY:	all clean fclean re
