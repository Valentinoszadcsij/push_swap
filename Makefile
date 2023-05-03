
NAME:=	push_swap
SRC:= 	main.c parser.c error.c utils.c
		
OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=address

CC:= cc

all: $(NAME)

$(NAME): $(OBJ)
	make re -C lib/libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) lib/libft/libft.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f push_swap
re: fclean all