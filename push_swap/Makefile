FILES = main.c utils.c sorting_algorithms.c operations_p.c operations_s.c \
	operations_r.c

FILES_BONUS =

LIBFT = libft/libft.a

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS = $(FILES_BONUS:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

LIBFT_CLEAN = make fclean -C libft

NAME = push_swap

NAME_BONUS = checker

all: $(NAME)

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT)

clean:
	$(LIBFT_CLEAN)
	${RM} $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(LIBFT_CLEAN)
	${RM} $(NAME) $(NAME_BONUS) $(OBJECTS) $(OBJECTS_BONUS)

re: fclean bonus

bonus: all $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJECTS_BONUS) $(LIBFT)

.PHONY:	all clean fclean re