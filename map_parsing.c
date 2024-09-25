/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:30:28 by iduric            #+#    #+#             */
/*   Updated: 2024/09/05 16:44:53 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_parsing(t_game *map_specs)
{
	map_specs->fd = open(map_specs->path, O_RDONLY); // open
	if (map_malloc(map_specs))
		return (ft_error(map_specs, 2));
	if (map_cpy(map_specs))
		return (ft_error(map_specs, 3));
	close(map_specs->fd); // close
	if (ft_error(map_specs, wall_check(map_specs)))
		return (1);
	if (map_specs->set[0] != 1 || map_specs->set[1] < 1
		|| map_specs->set[2] != 1)
		return (ft_error(map_specs, 4));
	if (path_checker(map_specs, map_specs->p_co[0], map_specs->p_co[1]) == 0)
		return (ft_error(map_specs, 7));
	if (map_specs->set[1] != 0)
		return (ft_error(map_specs, 8));
	else
		ft_printf("Map is valid, yay.\n");
	setback_chars(map_specs, 0, 0);
	return (0);
}
