##
## EPITECH PROJECT, 2023
## makefile
## File description:
## my_ls
##

SRC	=	src/main.c	\
		src/minimap.c	\
		src/tools/is_pressed.c	\
		src/handle_collision.c	\
		src/map/init_map.c	\
		src/map/create_tiles.c	\
		src/initialization/init_enemies.c	\
		src/initialization/init_enemies_tab.c	\
		src/initialization/init_structs.c	\
		src/initialization/init_window.c	\
		src/initialization/init_player.c	\
		src/initialization/init_graphics.c	\
		src/initialization/init_sounds.c	\
		src/display_walls.c \
		src/rays/cast_rays.c \
		src/game_loop.c	\
		src/print_fps.c	\
		src/move_player.c \
		src/menu/display_menu.c \
		src/menu/change_settings.c \
		src/menu/options_menu.c \
		src/menu/init_menu.c \
		src/menu/game_over.c \
		src/menu/rain_circles.c \
		src/menu/win.c \
		src/menu/init_option_menu.c \
		src/hud/display_fps.c \
		src/hud/display_score.c \
		src/ennemies/display_ennemies.c \
		src/ennemies/ennemies_attack.c \
		src/tools/move_rect.c \
		src/tools/normalize_angle.c \
		src/tools/set_cursor_pos.c \
		src/ennemies/update_animation.c \
		src/ennemies/count_ennemies.c \
		src/map/generate_map.c \
		src/map/save_map.c \
		src/handle_shoot.c \
		src/handle_game_event.c \
		src/is_shot.c \
		src/gain_health.c \
		src/toggle_light.c \
		src/handle_error.c

OBJ	=	$(SRC:.c=.o)

NAME	=	wolf3d

CFLAGS = -Wextra -Wall -I ./include/ -l csfml-graphics -l csfml-system \
	-l csfml-window -l csfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

opti:	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -pg
	timeout 10s ./wolf3d || true
	gprof ./wolf3d gmon.out > result.txt

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
