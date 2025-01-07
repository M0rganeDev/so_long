CFLAGS = -Wextra -Wall -Werror -ggdb

LIBS = ./libs/

INCLUDES += -I$(LIBS)libft -I$(LIBS)minilibx-linux -I./includes
LDFLAGS = $(INCLUDES) -lXext -lX11 -lm -lz -L$(LIBS)minilibx-linux -lmlx -L$(LIBS)libft -lft

SOURCES = src/main.c \
		  src/player.c \
		  src/rendering/renderer.c \
		  src/rendering/renderer_util.c \
		  src/rendering/texture_loader.c \
		  src/parser/get_next_line.c \
		  src/parser/map_parser.c \
		  src/parser/validator.c \
		  src/parser/floodfill.c \
		  src/parser/map_leak.c \
		  src/utils/vector.c \
		  src/utils/utils.c \
		  src/utils/asset_cleaner.c \
		  src/utils/error.c \

SBONUS = bonus/enemy.c \
		 bonus/enemy_utils.c \
		 bonus/score.c

ifeq ($(BONUS),1)
	CFLAGS += -DIS_BONUS=1
	SOURCES += $(SBONUS)
else
	# stupid norm saying my file is 7 functions long when one
	# there's clearly 3 or 4 depending on if IS_BONUS is set
	SOURCES += src/utils/mock_enemy_utils.c
	SOURCES += src/utils/mock_bonus_utils.c
endif

OBJECTS = $(SOURCES:.c=.o)

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECTS)
	echo $(BONUS)
	cc $(CFLAGS)  $(OBJECTS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	cc $(CFLAGS) -c $(INCLUDES) $< -o $@

run:
	./so_long.a

clean:
	make -C ./libs/libft clean
	make -C ./libs/minilibx-linux clean
	find . -name '*.o' -delete

fclean: clean
	rm -f $(NAME)
	make -C ./libs/libft fclean
	# minilibx does not have a fclean task. Too bad !
	make -C ./libs/minilibx-linux clean

prepare:
	@git clone https://github.com/42Paris/minilibx-linux.git libs/minilibx-linux

gpush: fclean
	@rm -rf ./libs/minilibx-linux

gpull: prepare
	make libs
	make all

bonus:
	make all BONUS=1

libs:
	make -C ./libs/libft
	make -C ./libs/minilibx-linux

re:
	make fclean
	make libs
	make

rebonus:
	make fclean
	make libs
	make bonus

.PHONY: all run clean fclean libs bonus re rebonus
