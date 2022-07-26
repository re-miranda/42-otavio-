NAME=../libftprintf.a
SRCS=ft_printf.c ft_print.c ft_hexa.c ft_itoa.c ft_printf_strchr.c
OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS= -O3 -Werror -Wall -Wextra

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
