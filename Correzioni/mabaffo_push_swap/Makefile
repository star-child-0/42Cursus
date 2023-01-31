NAME			:=	push_swap

BNAME			:=	checker

SRCS_DIR		:=	./srcs/

FILES		:=	main.c \
				ft_check_and_create.c \
				ft_check_args.c \
				ft_check_ints.c \
				ft_lst_issorted.c \
				ft_puterror.c \
				swap.c \
				push.c \
				rotate.c \
				rrotate.c \
				ft_sort3.c \
				ft_lilsort.c \
				ft_findmin.c \
				ft_sort.c \

BFILES		:=	checker_bonus.c \
				ft_check_and_create.c \
				ft_check_args.c \
				ft_check_ints.c \
				ft_lst_issorted.c \
				ft_puterror.c \
				swap.c \
				push.c \
				rotate.c \
				rrotate.c \
				get_next_line.c \

SRCS			:=	$(addprefix $(SRCS_DIR), $(FILES))

BSRCS			:=	$(addprefix $(SRCS_DIR), $(BFILES))

OBJS			:=	$(SRCS:.c=.o)

BOBJS			:=	$(BSRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

CC				:=	gcc

FLAGS			:=	-Wall -Wextra -Werror -g

CLR_RMV			:=	\033[0m
RED				:=	\033[1;31m
GREEN			:=	\033[1;32m
YELLOW			:=	\033[1;33m
BLUE			:=	\033[1;34m
CYAN			:=	\033[1;36m

RM				:=	rm -f

LIBFT			:=	libft/libft.a
LIBFTMAKE		:=	make -sC libft
LIBFTMAKEBONUS	:=	make -sC libft bonus

$(NAME):	$(OBJS)
			@$(LIBFTMAKE)
			@$(LIBFTMAKEBONUS)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
			@echo "$(GREEN)$(NAME) created ✔️ ${CLR_RMV}"

bonus:		$(BOBJS)
			@$(LIBFTMAKE)
			@$(LIBFTMAKEBONUS)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(BNAME) ${CLR_RMV}..."
			@$(CC) $(FLAGS) $(BOBJS) $(LIBFT) -o $(BNAME)
			@echo "$(GREEN)$(BNAME) created ✔️ ${CLR_RMV}"

all:			$(NAME) $(BONUS)

clean:
				@ make -sC ./libft clean
				@ ${RM} *.o */*.o */*/*.o
				@ echo "$(RED)Deleting $(CYAN)objs $(CLR_RMV)✔️"

fclean:			clean
				@ $(RM) $(NAME) $(BNAME) $(LIBFT)
				@ echo "$(RED)Deleting $(CYAN)binaries $(CLR_RMV)✔️"

re:				fclean all

.PHONY:			all clean fclean re bonus
.SILENT:
