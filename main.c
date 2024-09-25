/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:50:24 by iduric            #+#    #+#             */
/*   Updated: 2024/09/20 11:50:24 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		data;

	struct_init(&data);
	if (argc != 2)
	{
		ft_printf("Error: invalid number of arguments.\n");
		return (1);
	}
	data.path = argv[1];
	data.fd = open(data.path, O_RDONLY); // open
	if (data.fd == -1)
		return (1);
	if (dim_check(&data))
		return (ft_error(&data, 1));
	close(data.fd); // close
	if(map_parsing(&data))
		return (0);
	so_long_mlx_init(&data);
	display_map(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, manage_hook, (void *)&data); //Here, "2" (KeyPress) is a constant that corresponds to the X11 event for a key press, and "1L << 0" (KeyPressMask) tells the system you want to listen for key press events.
	mlx_mouse_hide();
	mlx_loop(data.mlx);
	free_map(&data, data.malloc_y); //ever useless?
	return (0);
}
