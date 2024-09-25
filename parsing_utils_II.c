/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_II.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:06 by iduric            #+#    #+#             */
/*   Updated: 2024/09/05 16:45:55 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_cpy(t_game *map_specs)
{
	int	i;

	i = 0;
	while (i < map_specs->map_y)
	{
		map_specs->map_cpy[i] = ft_strdup(get_next_line(map_specs->fd));
		map_specs->map_cpy[i][map_specs->map_x] = '\0';
		i++;
	}
	return (0);
}

int	char_counter(t_game *map_specs, int y, int x)
{
	if (map_specs->map_cpy[y][x] == 'P')
	{
		map_specs->p_co[0] = y;
		map_specs->p_co[1] = x;
		map_specs->set[0]++;
	}
	else if (map_specs->map_cpy[y][x] == 'C')
		map_specs->set[1]++;
	else if (map_specs->map_cpy[y][x] == 'E')
	{
		map_specs->e_co[0] = y;
		map_specs->e_co[1] = x;
		map_specs->set[2]++;
	}
	else if (map_specs->map_cpy[y][x] == '0')
		map_specs->set[3]++;
	else if (map_specs->map_cpy[y][x] == '1')
		map_specs->set[4]++;
	else
		return (1);
	return (0);
}

int	wall_check(t_game *map_specs)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map_specs->map_y)
	{
		while (x < map_specs->map_x)
		{
			if (char_counter(map_specs, y, x))
				return (5);
			if (y == 0 || y == map_specs->map_y - 1 || x == 0
				|| x == map_specs->map_x - 1)
			{
				if (map_specs->map_cpy[y][x] != '1')
					return (6);
			}
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

int	path_checker(t_game *map_specs, int y, int x)
{
	int	i;

	i = 0;
	if (x == map_specs->map_x - 1 || y == map_specs->map_y - 1 || x == 0
		|| y == 0 || map_specs->map_cpy[y][x] == '1'
		|| map_specs->map_cpy[y][x] == 'X' || map_specs->map_cpy[y][x] == 'A'
		|| map_specs->map_cpy[y][x] == 'H')
		return (0);
	if (map_specs->map_cpy[y][x] == 'E')
		return (1);
	if (map_specs->map_cpy[y][x] == '0')
		map_specs->map_cpy[y][x] = 'X';
	if (map_specs->map_cpy[y][x] == 'P')
		map_specs->map_cpy[y][x] = 'H';
	if (map_specs->map_cpy[y][x] == 'C')
	{
		map_specs->set[1]--;
		map_specs->map_cpy[y][x] = 'A';
	}
	i += path_checker(map_specs, y, x + 1);
	i += path_checker(map_specs, y, x - 1);
	i += path_checker(map_specs, y + 1, x);
	i += path_checker(map_specs, y - 1, x);
	return (i);
}

void	setback_chars(t_game *map_specs, int y, int x)
{
	while (y < map_specs->map_y)
	{
		while (x < map_specs->map_x)
		{
			if (map_specs->map_cpy[y][x] == 'X')
				map_specs->map_cpy[y][x] = '0';
			if (map_specs->map_cpy[y][x] == 'A')
			{
				map_specs->set[1]++;
				map_specs->map_cpy[y][x] = 'C';
			}
			if (map_specs->map_cpy[y][x] == 'H')
				map_specs->map_cpy[y][x] = 'P';
			x++;
		}
		x = 0;
		y++;
	}
}
