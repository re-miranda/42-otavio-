NAME=../linked_list.a
SRCS=linked_list.c
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
