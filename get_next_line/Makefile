NAME=../get_next_line.a
SRCS=get_next_line.c
OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS= -O3 -Werror -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
