CFILES		=		ft_printf.c utils_1.c utils_2.c
CFLAGS		=		-Wall -Werror -Wextra
OBJDIR		=		obj
OBJ			=		$(addprefix $(OBJDIR)/, $(CFILES:.c=.o))
NAME		=		libftprintf.a

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o: %.c
	cc -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	ar rcs $@ $^

.PHONY: clean fclean all re

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJDIR)
	rm -f main

re: fclean all
