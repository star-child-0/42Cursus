FILES = main.c sorting_algorithms.c lis_algorithm.c\
	mov.c scmoovin.c\
	utils.c utils2.c utils3.c utils4.c \
	operations_p.c operations_s.c operations_r.c operations_r2.c
	
BONUS_FILES = checker.c checker_utils.c checker_utils2.c \
		checker_operations.c checker_operations2.c

LIBFT = ../libft/libft.a

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(FILES))

BONUS_SRC = $(addprefix $(SRC_DIR), $(BONUS_FILES))

OBJECTS = $(SRC:.c=.o)

BONUS_OBJECTS = $(BONUS_SRC:.c=.o)

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

clean:
	make clean -C ../libft
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	make fclean -C ../libft
	$(RM) $(NAME) $(BONUS_NAME) $(OBJECTS) $(BONUS_OBJECTS)

re: fclean bonus

.PHONY:	all clean fclean re
.SILENT: all clean fclean re