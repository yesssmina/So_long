# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 13:30:26 by sanaggar          #+#    #+#              #
#    Updated: 2023/06/10 16:38:23 by sanaggar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -v

SRC =	so_long_parsing.c \
		main.c \
		./GNL/get_next_line.c \
		./GNL/get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

$(NAME): $(OBJ)
	make -C ./Libft/
	cp ./Libft/libft.a $(NAME)
	make -C ./Printf/
	cp ./Printf/libftprintf.a $(NAME)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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
