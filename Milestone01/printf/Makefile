SRCS = \
ft_printf.c \
print_char_str.c \
print_hex_ptr_nbr.c \

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re