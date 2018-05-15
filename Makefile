# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/14 15:11:01 by dchiche           #+#    #+#              #
#    Updated: 2018/05/15 16:53:31 by dchiche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra
LIB = ./
SRCS =  main.c \
		log.c \
		parse/checking.c \
		parse/parse_connexions.c \
		parse/parse.c \
		output/print_room.c \
		output/print_elem.c \
		output/print_path.c \
		structure/find_room.c \
		structure/free_room.c \
		structure/is_connected.c \
		structure/room_cmp.c \
		algo/dijkstra.c \
		algo/solve.c \
		algo/print_lem_in.c

SRCS := $(addprefix srcs/, $(SRCS))
OBJ = $(SRCS:.c=.o)

all : lib $(NAME)

$(NAME) : $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./libft/ -lft
	@echo "> Lem-in has been made :)"

lib :
	@make -C ./libft/ all

%.o : %.c
	@echo "=\c"
	@gcc $(FLAGS) -I $(LIB) -c $? -o $@

clean :
	@echo "----> Lem-in has been cleaned :)"
	@rm -rf $(OBJ)
	@make -C ./libft/ fclean

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: fclean lib clean re all
