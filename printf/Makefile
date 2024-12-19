SRC_FILES = ft_printf.c \
ft_print_functions.c \
ft_print_functions2.c \
ft_print_ptr.c \
ft_print_hexa.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

OBJFILES = $(SRC_FILES:.c=.o)

AR = ar -rc
NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(NAME) $(OBJFILES)
	ranlib $(NAME)


clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all


.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
