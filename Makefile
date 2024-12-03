CFLAGS = -Wextra -Wall -Werror -ggdb

LIBS = ./libs/

INCLUDES += -I$(LIBS)libft -I$(LIBS)minilibx-linux 
LDFLAGS = $(INCLUDES) -lXext -lX11 -lm -lz -L$(LIBS)minilibx-linux -lmlx -L$(LIBS)libft -lft

SOURCES = src/main.c \
		  src/renderer.c \
		  src/gnl/get_next_line.c \
		  src/parser/map_parser.c \
		  src/parser/validator.c \
		  src/vector.c \
		  src/player.c \
		  src/renderer_util.c \
		  src/utils.c \
		  src/parser/floodfill.c \
		  src/parser/map_leak.c


OBJECTS = $(SOURCES:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS)  $(OBJECTS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	cc $(CFLAGS) -c $(INCLUDES) $< -o $@

run: $(NAME)
	./so_long.a

clean:
	rm -f $(OBJECTS)
	make -C ./libs/libft clean
	make -C ./libs/minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	# minilibx does not have a fclean task. Too bad !
	make -C ./libs/minilibx-linux clean

prepare:
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux

gpush: fclean
	rm -rf ./libs/minilibx-linux

gpull: prepare
	make libs
	make all

libs:
	make -C ./libs/libft
	make -C ./libs/minilibx-linux

.PHONY: all run clean fclean libs
