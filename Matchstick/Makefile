##
## EPITECH PROJECT, 2021
## Matchstick
## File description:
## Makefile
##

SRC		=	src/ai.c	\
			src/error.c	\
			src/file_struct.c	\
			src/game_loop.c	\
			src/input_handling.c	\
			src/lib.c	\
			src/print.c	\
			src/set_lines.c	\
			src/set_tab.c	\
			src/utils.c

OBJ		=	$(SRC:.c=.o)

NAME	=	matchstick

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -Werror -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) src/main.c $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) *.gcno *.gcda
	rm -f unit_test
	rm -f *vgcore*
	rm -f *.gcno
	rm -f *.gcda

unit_test:
	$(CC) tests/test_one.c tests/test_two.c $(SRC) -o unit_test $(CFLAGS) --coverage -lcriterion

tests_run:	unit_test
	./unit_test

re: fclean all

.PHONY:	all clean fclean re