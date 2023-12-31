CFILES		=		arg_checking.c ft_printf.c utils_1.c utils_2.c
CFLAGS		=		-Wall -Werror -Wextra
OBJ			=		$(CFILES:.c=.o)
NAME		=		libftprintf.a

all: $(NAME)

%.o: %.c
	cc -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	ar rcs $@ $^

.PHONY: clean fclean all re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
