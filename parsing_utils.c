/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:25:51 by iduric            #+#    #+#             */
/*   Updated: 2024/09/05 16:46:06 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_game *map_specs)
{
	map_specs->map_cpy = NULL;
	map_specs->set[0] = 0;
	map_specs->set[1] = 0;
	map_specs->set[2] = 0;
	map_specs->set[3] = 0;
	map_specs->set[4] = 0;
	map_specs->map_y = 0;
	map_specs->map_x = 0;
	map_specs->malloc_y = 0;
	map_specs->fd = 0;
	map_specs->path = NULL;
}

int	dim_check(t_game *map_specs)
{
	char	*temp;

	temp = get_next_line(map_specs->fd);
	map_specs->map_x = ft_strlen(temp) - 1;
	while (temp != NULL)
	{
		map_specs->map_y++;
		if (ft_strlen(temp) - 1 != (size_t)map_specs->map_x)
		{
			free(temp);
			return (1);
		}
		temp = get_next_line(map_specs->fd);
	}
	if (map_specs->map_y == map_specs->map_x || map_specs->map_y < 3
		|| map_specs->map_x < 3)
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

int	free_map(t_game *map_specs, int i)
{
	if (map_specs->map_cpy != NULL)
	{
		while (i >= 0)
		{
			free(map_specs->map_cpy[i]);
			i--;
		}
		free(map_specs->map_cpy);
	}
	return (0);
}

int	ft_error(t_game *map_specs, int code)
{
	if (code == 0)
		return (0);
	if (code == 1)
		ft_printf("Error: invalid map dimensions.\n");
	else if (code == 2)
		ft_printf("Error: memory allocation failed.\n");
	else if (code == 3)
		ft_printf("Error: map copying failed.\n");
	else if (code == 4)
		ft_printf("Error, invalid number of player, collectible or exit.\n");
	else if (code == 5)
		ft_printf("Error, invalid character found in map.\n");
	else if (code == 6)
		ft_printf("Error, map isn't surrounded by walls.\n");
	else if (code == 7)
		ft_printf("Error, no path from player to exit.\n");
	else if (code == 8)
		ft_printf("Error, not all collectibles are accessible.\n");
	if (map_specs->fd)
		close(map_specs->fd);
	free_map(map_specs, map_specs->malloc_y);
	return (1);
}

int	map_malloc(t_game *map_specs)
{
	map_specs->malloc_y = 0;
	map_specs->map_cpy = malloc(sizeof(char **) * (map_specs->map_y + 1));
	if (map_specs->map_cpy == NULL)
		return (free_map(map_specs, -1));
	while (map_specs->malloc_y < map_specs->map_y)
	{
		map_specs->map_cpy[map_specs->malloc_y] = malloc(sizeof(char *)
				* map_specs->map_x + 1);
		if (map_specs->map_cpy[map_specs->malloc_y] == NULL)
			return (free_map(map_specs, map_specs->malloc_y));
		map_specs->malloc_y++;
	}
	map_specs->map_cpy[map_specs->malloc_y] = NULL;
	map_specs->malloc_y--;
	return (0);
}
