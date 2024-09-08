#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct s_testmap
{
	char	**map_cpy;
	int		set[5];  // [player, collectible, exit, space, wall]
	int		p_co[2];
	int		map_y;
	int		map_x;
	int		malloc_y;
	int		fd;
	char	*path;
}   t_testmap;

void	struct_init(t_testmap *map_specs);
int		dim_check(t_testmap *map_specs);
int		free_map(t_testmap *map_specs, int i);
int		ft_error(t_testmap *map_specs, int code);
int		map_malloc(t_testmap *map_specs);
int		map_cpy(t_testmap *map_specs);
int		char_counter(t_testmap *map_specs, int y, int x);
int		wall_check(t_testmap *map_specs);
int		path_checker(t_testmap *map_specs, int y, int x);
void	setback_chars(t_testmap *map_specs, int y, int x);

#endif