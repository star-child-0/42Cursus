CLIENT_FILES = client.c
SERVER_FILES = server.c

LIBFT = ../libft/libft.a

CLIENT_OBJ = $(CLIENT_FILES:.c=.o)
SERVER_OBJ = $(SERVER_FILES:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER) 

$(CLIENT): $(CLIENT_OBJ)
	make -C ../libft
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(LIBFT)

$(SERVER): $(SERVER_OBJ)
	make -C ../libft
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(LIBFT)
	clear

clean:
	make clean -C ../libft
	$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	make fclean -C ../libft
	$(RM) $(CLIENT) $(SERVER)
	clear

re: fclean all

.PHONY:	all clean fclean re
