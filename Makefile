##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make a file
##

SRC 	=	src/navy.c				\
			src/my_getnbr.c			\
			src/my_putstr.c 		\
			src/my_put_nbr.c 		\
			src/my_printf.c			\
			src/get_next_line.c 	\
			src/my_putchar.c 		\
			src/load_and_fill.c 	\
			src/game.c 				\
			src/players.c 		\
			src/coord.c 			\
			src/my_strlen.c 		\

OBJ 	= 	$(SRC:.c=.o)

NAME	=	navy

CC = gcc -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

test_run:
		$(CC) -o unit_test bonus/testcriterion.c $(SRC) -lcriterion
		./unit_test

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
