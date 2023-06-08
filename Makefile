
NAME:=	push_swap
SRC:= 	parser.c error.c utils.c swap.c push.c rotate.c reverse_rotate.c push_swap.c exec_flags.c\
		quick_select.c sort_utils.c
SRC_MAIN = main.c
BSRC:=	bonus/checker.c lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c

OBJ:=	$(SRC:.c=.o)

OBJ_MAIN:= $(SRC_MAIN:.c=.o)

BOBJ:=	$(BSRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra
# FLAGS+= -g3 -fsanitize=address

CC:= cc

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	make re -C lib/libft
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_MAIN) $(OBJ) lib/libft/libft.a
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
bonus: $(OBJ) $(BOBJ)
	$(CC) $(FLAGS) $(BOBJ) $(OBJ) lib/libft/libft.a -o checker
clean:
	rm -f $(OBJ) $(BOBJ) $(OBJ_MAIN)
fclean: clean
	rm -f push_swap checker
re: fclean all