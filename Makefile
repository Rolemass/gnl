NAME = gnl
INCLUDES = ./get_next_line.h
SRC = ./get_next_line.c main.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIB = ./libft

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./libft/libft.h -o $@ -c $<

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) -L $(LIB) -lft -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)
	make -C Libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all
