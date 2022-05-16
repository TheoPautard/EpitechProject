SRC		=		src/errorhandling.c	\
				src/main.c	\
				src/PWGenerator.c

OBJ		=		$(SRC:.c=.o)

NAME	=		PWGenerator

CC		=		gcc -o

RM		=		rm -rf

CFLAGS	=		-W -Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(CC) $(NAME) $(SRC) $(CFLAGS)

all: $(NAME)

re: fclean all

clean:
	$(RM) src/*.o

fclean: clean
	$(RM) $(NAME)

PHONY: re fclean clean all

