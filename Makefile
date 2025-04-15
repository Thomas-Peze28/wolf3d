##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my_ls
##

SRC	=	src/main.c	\
		src/display.c	\
		src/handle_collision.c 	\
		src/init_structs.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf

CFLAGS = -Wextra -Wall -I ./include/ -l csfml-graphics -l csfml-system \
	-l csfml-window -l csfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
