NAME=main.out
SRCS=main.c
ARCH=get_next_line.a libft.a libftprintf.a
LIB=lib.a
CC=cc
CFLAGS= -O3 -Werror -Wall -Wextra -g3

all: $(NAME)

$(LIB): $(ARCH)
	ar -rcT $(LIB) $(ARCH)

$(ARCH):
	make -C ./ft_printf
	make -C ./get_next_line
	make -C ./libft

$(NAME): $(LIB)
	$(CC) $(SRCS) $(LIB) -o $(NAME)

clean:
	rm -rf $(ARCH)
	make -C ./ft_printf clean
	make -C ./get_next_line clean
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME) $(LIB)
	make -C ./ft_printf fclean
	make -C ./get_next_line fclean
	make -C ./libft fclean

re: fclean all
