# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iragusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/29 14:29:23 by iragusa           #+#    #+#              #
#    Updated: 2022/11/10 23:28:23 by iragusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted.

# -c = Compile or assemble the source files, but do not link.
# cp = copy.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.

NAME = libftprintf.a

CC = gcc

AR = ar -rcs

FLAG = -Werror -Wall -Wextra

SRC = ft_putdiu.c ft_printf.c \
      ft_wdt_prec.c ft_checkchar.c ft_print_tab.c ft_funlen.c \
      ft_putcsp.c ft_put_x.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

%.o: %.c
	$(CC) -c $(FLAG) -I. $< -o $@
	
bonus: all

clean: 
	$(MAKE) clean -C ./libft
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all
 
.PHONY: all clean fclean re
