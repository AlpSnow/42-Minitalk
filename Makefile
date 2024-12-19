# Program names
NAME_CLIENT = client
NAME_SERVER = server

# Source files
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Object files
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

# Paths for libraries
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf

# Library files
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Rules
all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(LIBFT) $(PRINTF)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER) $(LIBFT) $(PRINTF)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all
