/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgane <git@morgane.dev>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:00:47 by morgane           #+#    #+#             */
/*   Updated: 2025/01/06 13:34:12 by morgane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SCALE 32
# define PLAYER_BIT_START 3

// only set to 1 to get LSP working
// in IS_BONUS related branches
# ifndef IS_BONUS
#  define IS_BONUS 0
# endif

# define PLAYER_TEXTURE "./textures/player.xpm"
# define PLAYER_TEXTURE_FACING_LEFT "./textures/player_left.xpm"
# define WALL_FULL_ALL_SIDES "./textures/wall_full_all_sides.xpm"
# define WALL_EMPTY_ALL_SIDES "./textures/wall_empty_all_sides.xpm"
# define WALL_SIDE_LEFT	"./textures/wall_side_left.xpm"
# define WALL_SIDE_UNDER "./textures/wall_side_under.xpm"
# define WALL_SIDE_RIGHT "./textures/wall_side_right.xpm"
# define WALL_SIDE_OVER "./textures/wall_side_over.xpm"
# define WALL_CORNER_TOP_RIGHT "./textures/wall_corner_top_right.xpm"
# define WALL_CORNER_TOP_LEFT "./textures/wall_corner_top_left.xpm"
# define WALL_CORNER_BOTTOM_RIGHT "./textures/wall_corner_bottom_right.xpm"
# define WALL_CORNER_BOTTOM_LEFT "./textures/wall_corner_bottom_left.xpm"
# define WALL_TWO_SIDES_LEFT_RIGHT "./textures/wall_two_sides_left_right.xpm"
# define WALL_TWO_SIDE_TOP_DOWN "./textures/wall_two_side_top_down.xpm"
# define WALL_EMPTY_BOTTOM "./textures/wall_empty_bottom.xpm"
# define WALL_EMPTY_LEFT "./textures/wall_empty_left.xpm"
# define WALL_EMPTY_TOP "./textures/wall_empty_top.xpm"
# define WALL_EMPTY_RIGHT "./textures/wall_empty_right.xpm"
# define GROUND_TEXTURE "./textures/ground.xpm"
# define COLLECTIBLE_TEXTURE "./textures/collectible.xpm"
# define EXIT_TEXTURE "./textures/exit.xpm"
# define DEBUG_TEXTURE "./textures/debug.xpm"
# define ENEMY_TEXTURE "./textures/enemy.xpm"
# define STEP_LABEL_TEXTURE "./textures/step_label.xpm"
# define COLLECTED_TEXTURE "./textures/collected.xpm"
# define NUMBERS_TILEMAP_TEXTURE "./textures/numbers.xpm"
# define SLASH_TEXTURE "./textures/slash.xpm"

// used to tell if if the is won and we need to clean up
// and free memory all over the program
# define GF_GAME_OBJECTIVE_WON 2

// used to refresh the tiles on screen if needed
# define GF_NEED_WORLD_REFRESH 4

// ---------------------   player state bit masks  --------------------

// used to move the player if needed
# define GF_PLAYER_IS_MOVING 8

/*
 * Note : GF_PLAYER_MOVING_DIR dictate whether or not
 * the player move up (if the bit is not set), or left (if the bit is set)
 * GF_PLAYER_MOVING_INV dictate whether or not
 * this direction is reverted (norml if not set, inverted otherwise).
 * if inverted, GF_PL_MOV_DIR will go one case under if DIR is not set
 * right otherwise
*/
# define GF_PLAYER_M_DIR 16
# define GF_PLAYER_M_INV 32
# define GF_PLAYER_M_INV_TXT 64

// simple vector of coordinate in a 2D space
typedef struct s_vector2i
{
	int	x;
	int	y;
}		t_vector2i;

// util method to add two vectors without changing the base vector
t_vector2i	vector_add(t_vector2i base, int flag);

// util method to add something to a vector without changing the base vector
t_vector2i	vector_add_lit(t_vector2i base, int x, int y);

// struct that has a pointer to every textures
// this allows to only allocate memory for a unique instance of the texture
// instead of allocating memory for each tile that use the texture
typedef struct s_textures
{
	void				*player;
	void				*player_left;
	void				*ground;
	void				*collectible;
	void				*exit;
	void				*enemy;
	void				*wall_full_all_sides;
	void				*wall_empty_all_sides;
	void				*wall_side_left;
	void				*wall_side_under;
	void				*wall_side_right;
	void				*wall_side_over;
	void				*wall_corner_top_right;
	void				*wall_corner_top_left;
	void				*wall_corner_bottom_right;
	void				*wall_corner_bottom_left;
	void				*wall_two_sides_left_right;
	void				*wall_two_side_top_down;
	void				*wall_empty_bottom;
	void				*wall_empty_left;
	void				*wall_empty_top;
	void				*wall_empty_right;
	void				*debug;
	void				*step_label;
	void				*collected;
	void				*slash;
	void				*nbr_zero;
	void				*nbr_one;
	void				*nbr_two;
	void				*nbr_three;
	void				*nbr_four;
	void				*nbr_five;
	void				*nbr_six;
	void				*nbr_seven;
	void				*nbr_eight;
	void				*nbr_nine;
}				t_textures;

// main struct, contains windows data, map properties,
// player coordinates, and so on.
// game_flags is interacted with through bit manipulation 
// (see GF flags at the beggining of the file.)

# if !IS_BONUS

typedef struct s_game_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map_data;
	t_vector2i	map_size;
	t_vector2i	player_pos;
	t_textures	textures;
	int			collectible_count;
	int			base_collectible;
	char		*exit;
	int			game_flags;
	int			can_step;
	int			player_step;
	int			enemy_count;
}				t_game_data;
# else

// in the map file, an enemy is marked as an F (for foe)
#  define ENEMY_CHR F

#  define ENEMY_DEFAULT_SPEED 16

#  define ENEMY_WAIT_FRAME 60

// move up or down
#  define MOVE_Y_BIT 1
#  define IS_MOVING_BIT 2
#  define IS_MOVING_INVERTED_BIT 4

// note : 
// dir is not used as a litteral char, but as a 8 bit integer
// as it it the smallest int we have at hand for bitshift operations
// as of right now, only the 4 lowest bits are used
// speed : time in frames to get from a tile to another. 0 will make them snap
// to their next tile instantly and use mercy_frame as a timer
typedef struct s_enemy
{
	int				dir;
	t_vector2i		pos;
	unsigned int	speed;
	unsigned int	mercy_frame;
}	t_enemy;

typedef struct s_game_data
{
	void		*mlx;
	void		*mlx_win;
	char		**map_data;
	t_vector2i	map_size;
	t_vector2i	player_pos;
	t_textures	textures;
	int			collectible_count;
	int			base_collectible;
	char		*exit;
	int			game_flags;
	int			player_step;
	int			can_step;
	t_enemy		*enemies;
	int			enemy_count;
}				t_game_data;
# endif
#endif
