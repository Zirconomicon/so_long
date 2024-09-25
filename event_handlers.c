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

void	move(t_game *game, int y, int x)
{
	if (game->map_cpy[y][x] != '1' && game->map_cpy[y][x] != 'E')
	{
		ft_printf("Move number %d.\n", game->move_count);
		game->move_count++;
		if (game->map_cpy[y][x] == 'C')
		{
			game->set[1]--;
			if (game->set[1] == 0)
				game->map_cpy[game->e_co[0]][game->e_co[1]] = 'O';
		}
		else if (game->map_cpy[y][x] == 'O')
		{
			ft_printf("GG!\n");
			//mlx_clear_window(game->mlx, game->mlx_win);
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit(0);
		}
		game->map_cpy[y][x] = 'P';
		game->map_cpy[game->p_co[0]][game->p_co[1]] = '0';
		game->p_co[0] = y;
		game->p_co[1] = x;
	}
	//return;
}

int	manage_hook(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)
		move(game, game->p_co[0] - 1, game->p_co[1]);
	if (keycode == 0 || keycode == 123)
		move(game, game->p_co[0], game->p_co[1] - 1);
	if (keycode == 1 || keycode == 125)
		move(game, game->p_co[0] + 1, game->p_co[1]);
	if (keycode == 2 || keycode == 124)
		move(game, game->p_co[0], game->p_co[1] + 1);
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	display_map(game);
	return (0);
}