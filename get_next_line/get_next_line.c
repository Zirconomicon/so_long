/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:58 by moturki           #+#    #+#             */
/*   Updated: 2024/09/02 22:02:17 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	info = {.fd = -1};
	char			*str;
	char			c;

	str = NULL;
	if (info.fd != fd)
		if (!init_info(&info, fd))
			return (NULL);
	c = set_char(&info);
	while (c)
	{
		str = ft_strjoin2(str, c);
		if (c == '\n')
			return (str);
		c = set_char(&info);
	}
	if (str != NULL && ft_strlen2(str) > 0)//
		str[ft_strlen2(str)] = '\n'; //modification pour la fonction dim_check de test.c dans so_long. Cette ligne ne devrait pas exister de base.
	return (str);
}
