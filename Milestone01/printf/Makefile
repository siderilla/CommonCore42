SRCS = \
ft_printf.c \
ft_printf_utils.c \

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