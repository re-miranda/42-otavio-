NAME=fdf

SRCS=fdf.c
OBJS=$(SRCS:.c=.o)

CC=cc
CFLAGS= -Werror -Wall -Wextra -g3
LINK= -lmlx -lm -lz -lXext -lX11 -Lmlx_linux

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LINK) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

valgrind:
	rm -rf valgrind.log
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes --log-file=valgrind.log ./$(NAME)

.PHONY: all clean fclean re