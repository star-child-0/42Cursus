
CSRCS			= client.c ft_atoi.c

SSRCS			= server.c ft_itoa.c

COBJS			= $(CSRCS:.c=.o)

SOBJS			= $(SSRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

SERVER			= server

CLIENT			= client

all:			$(SERVER) $(CLIENT)

$(SERVER):		$(SOBJS)
				 $(CC) $(CFLAGS) -o $(SERVER) $(SOBJS)
$(CLIENT):		$(COBJS)
				 $(CC) $(CFLAGS) -o $(CLIENT) $(COBJS)

clean:
				$(RM) $(COBJS) $(SOBJS)

fclean:			clean
				$(RM) $(SERVER) $(CLIENT)

re:				fclean all

