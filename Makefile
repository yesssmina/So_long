NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SOURCE_FOLDER = source

SRC =	./Lib/GNL/get_next_line.c \
		./Lib/GNL/get_next_line_utils.c \
		main.c \
		./$(SOURCE_FOLDER)/so_long_parsing.c \
		./$(SOURCE_FOLDER)/check_parsing.c \
		./$(SOURCE_FOLDER)/allocation_et_implementation_maps.c \
		./$(SOURCE_FOLDER)/ft_error.c \
		./$(SOURCE_FOLDER)/initialisation_structure.c \
		./$(SOURCE_FOLDER)/check_parsing_final.c \
		./$(SOURCE_FOLDER)/check_ber.c \
		./$(SOURCE_FOLDER)/mouv.c \
		./$(SOURCE_FOLDER)/mlx.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

$(NAME): $(OBJ)
	make -C ./Lib/Libft/
	make -C ./Lib/Printf/
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -L./Lib/Libft -lft -L./Lib/Printf -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ./Lib/Libft/
	make clean -C ./Lib/Printf/
	#make clean -C ./Lib/GNL/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./Lib/Printf/libftprintf.a
	rm -f ./Lib/Libft/libft.a

re:		fclean all
