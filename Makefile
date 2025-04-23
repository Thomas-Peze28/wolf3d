##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my_ls
##

SRC	=	src/main.c	\
		src/display.c	\
		src/handle_collision.c	\
		src/map/init_map.c	\
		src/map/create_tiles.c	\
		src/initialization/init_enemies.c	\
		src/initialization/init_structs.c	\
		src/display_walls.c \
		src/rays/cast_rays.c \
		src/game_loop.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

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
