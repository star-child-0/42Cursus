FILES = ft_printf.c flags.c ft_puts.c\
	ft_putchar.c ft_putstr.c ft_putnbr.c ft_nbrlen.c\

OBJECTS = $(FILES:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

bonus: all

$(NAME): $(OBJECTS)
	@echo "Compiling ft_printf"
	@$(CC) $(CFLAGS) -c $(FILES)
	@ar -rs libftprintf.a $(OBJECTS)
	@echo "Done"

clean:
	@echo "Cleaning"
	@$(RM) $(OBJECTS)
	@echo "Done"

fclean: clean
	@echo "Removing"
	@$(RM) $(NAME) $(OBJECTS)
	@echo "Done"

re: fclean bonus


.PHONY:	all clean fclean re bonus
.SILENT:
