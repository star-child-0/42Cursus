FILES = ft_printf.c flags.c\
	ft_putchar.c

LIBFT = ../libft/libft.a

SRC_DIR = ./src/

SRC = $(addprefix $(SRC_DIR), $(FILES))

OBJECTS = $(SRC:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling ft_printf"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)
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

.PHONY:	all clean fclean re
.SILENT:
