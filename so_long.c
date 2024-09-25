/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:50:19 by iduric            #+#    #+#             */
/*   Updated: 2024/09/05 20:53:48 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*char *texture_path_builder(char *folder, char *file)
{
	char *path;
	folder[ft_strlen(folder)] = '/';
	path = ft_strjoin(folder, file)
    return (path);
}

void	init_textures(t_game *game, char *folder)
{
	game->p_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "player"), &game->width, &game->height);
	game->c_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "collectible"), &game->width, &game->height);
	game->e_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "exit"), &game->width, &game->height);
	game->o_e_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "o_exit"), &game->width, &game->height);
	game->s_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "space"), &game->width, &game->height);
	game->w_txt = mlx_xpm_file_to_image(game->mlx, texture_path_builder(folder, "wall"), &game->width, &game->height);
}

void	level_maker(t_game *game, char *map, char *texture_pack)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_x * 96, game->map_y * 96, "minecraft: LE JEU");
	game->img = mlx_new_image(game->mlx, game->map_x * 96, game->map_y * 96);
}
*/

void	so_long_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->map_x * 96, game->map_y * 96, "minecraft: LE JEU");
	game->img = mlx_new_image(game->mlx, game->map_x * 96, game->map_y * 96);
	game->p_txt = mlx_xpm_file_to_image(game->mlx, "textures/player96.xpm", &game->width, &game->height);
	game->c_txt = mlx_xpm_file_to_image(game->mlx, "textures/collectible96.xpm", &game->width, &game->height);
	game->e_txt = mlx_xpm_file_to_image(game->mlx, "textures/exit96.xpm", &game->width, &game->height);
	game->o_e_txt = mlx_xpm_file_to_image(game->mlx, "textures/o_exit96.xpm", &game->width, &game->height);
	game->s_txt = mlx_xpm_file_to_image(game->mlx, "textures/space96.xpm", &game->width, &game->height);
	game->w_txt = mlx_xpm_file_to_image(game->mlx, "textures/wall96.xpm", &game->width, &game->height);
	game->move_count = 1;
}


void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map_y)
	{
		while (i < game->map_x)
		{
			if (game->map_cpy[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->s_txt, i * 96, j * 96);
			if (game->map_cpy[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->w_txt, i * 96, j * 96);
			if (game->map_cpy[j][i] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->p_txt, i * 96, j * 96);
			if (game->map_cpy[j][i] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->c_txt, i * 96, j * 96);
			if (game->map_cpy[j][i] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->e_txt, i * 96, j * 96);
			if (game->map_cpy[j][i] == 'O')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->o_e_txt, i * 96, j * 96);
			i++;
		}
		i = 0;
		j++;
	}
}
