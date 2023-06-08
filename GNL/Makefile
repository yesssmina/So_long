NAME = gnl.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =  get_next_line.c \
		get_next_line_utils.c \
		get_next_line_utils_bonus.c \
		get_next_line_bonus.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:		fclean all