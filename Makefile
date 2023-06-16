NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	so_long_parsing.c \
		check_parsing.c \
		allocation_et_implementation_maps.c \
		main.c \
		ft_error.c \
		initialisation_structure.c \
		mlx.c \
		check_parsing_final.c \
		check_ber.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

$(NAME): $(OBJ)
	make -C ./Libft/
	make -C ./Printf/
	$(CC) $(OBJ) -Lmlx -lmlx -L./Libft -lft -L./Printf -lftprintf -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C ./Libft/
	make clean -C ./Printf/
	#make clean -C ./GNL/
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ./Printf/libftprintf.a
	rm -f ./Libft/libft.a

re:		fclean all
