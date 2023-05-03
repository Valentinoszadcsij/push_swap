
NAME:=	libft.a
SRC:=	ft_atoi.c ft_split.c ft_isdigit.c ft_strlen.c

OBJ:=	$(SRC:.c=.o)

FLAGS:=	-Wall -Werror -Wextra

CC:= gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar -r $(NAME) $(OBJ)
%.o: %.c
	$(CC) -c $(FLAGS) $^ -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f libft.a
re: fclean all