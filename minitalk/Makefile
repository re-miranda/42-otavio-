SERVER=server
CLIENT=client

S_SRCS=server.c libput.c ft_strc.c
S_OBJS=$(S_SRCS:.c=.o)

C_SRCS=client.c libput.c libnum.c ft_atoi.c ft_striteri.c
C_OBJS=$(C_SRCS:.c=.o)

HEADER=minitalk.h

CC=cc
CFLAGS= -Werror -Wall -Wextra -g3 -O3

all: $(SERVER) $(CLIENT)

$(SERVER): $(S_OBJS)
	$(CC) $(S_OBJS) $(CFLAGS) $(LINK) -o $(SERVER)

$(CLIENT): $(C_OBJS)
	$(CC) $(C_OBJS) $(CFLAGS) $(LINK) -o $(CLIENT)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(S_OBJS) $(C_OBJS)


fclean: clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
