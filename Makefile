# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchiche <dchiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 17:49:15 by dchiche           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2018/05/09 18:25:35 by dchiche          ###   ########.fr        #
=======
#    Updated: 2018/05/13 15:56:19 by dchiche          ###   ########.fr        #
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra -Werror -fsanitize=address
LIB = ./
SRCS =  main.c \
		log.c \
		parse/checking.c \
		parse/parse_connexions.c \
		parse/parse.c \
		output/print_room.c \
<<<<<<< HEAD
=======
		output/print_elem.c \
		output/print_path.c \
>>>>>>> 365fd0c744d1717690f2f21e6b24868c11769b0d
		structure/find_room.c \
		structure/free_room.c \
		structure/is_connected.c \
		structure/room_cmp.c \
		algo/dijkstra.c
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
