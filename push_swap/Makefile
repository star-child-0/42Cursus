FILES = main.c sorting_algorithms.c lis_algorithm.c algorithm_selector.c \
	utils.c utils2.c mov.c exec_mov.c mov_reorder.c\
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

all: lib $(NAME)

bonus: all $(BONUS_NAME)

lib:
	make -sC ../libft

$(NAME): $(OBJECTS)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
	@echo "Done"

$(BONUS_NAME): $(BONUS_OBJECTS)
	@echo "Compiling push_swap bonus"
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJECTS) $(LIBFT)
	@echo "Done"

clean:
	@echo "Cleaning"
	@make clean -sC ../libft
	@$(RM) $(OBJECTS) $(BONUS_OBJECTS)
	@echo "Done"

fclean: clean
	@echo "Removing"
	@make fclean -sC ../libft
	@$(RM) $(NAME) $(BONUS_NAME) $(OBJECTS) $(BONUS_OBJECTS)
	@echo "Done"

re: fclean bonus

norm:
	norminette ./libft/
	norminette $(SRC)

.PHONY:	all clean fclean re bonus
.SILENT:
