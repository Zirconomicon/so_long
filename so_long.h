#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>

typedef struct s_game
{
	char	**map_cpy;
	int		set[5];  // [player, collectible, exit, space, wall]
	int		p_co[2]; // [y, x]
	int		e_co[2]; // [y, x]
	int		map_y;
	int		map_x;
	int		malloc_y;
	int		fd;
	char	*path;
	void	*img; // 42 docs variables
	/*char	*addr;
	int		bpp;
	int		line_length;
	int		endian;*/
	void	*mlx;// Pr. nassim variables
	void	*mlx_win;
	void	*p_txt;
	void	*c_txt;
	void	*e_txt;
	void	*o_e_txt;
	void	*s_txt;
	void	*w_txt;
	int		height;
	int		width;
	int		move_count;
}   t_game;

void	struct_init(t_game *map_specs);
int		dim_check(t_game *map_specs);
int		free_map(t_game *map_specs, int i);
int		ft_error(t_game *map_specs, int code);
int		map_malloc(t_game *map_specs);
int		map_cpy(t_game *map_specs);
int		char_counter(t_game *map_specs, int y, int x);
int		wall_check(t_game *map_specs);
int		path_checker(t_game *map_specs, int y, int x);
void	setback_chars(t_game *map_specs, int y, int x);
int		map_parsing(t_game *map_specs);
void	so_long_mlx_init(t_game *game);
void	display_map(t_game *game);
void	move(t_game *game, int y, int x);
int		manage_hook(int keycode, t_game *game);

#endif