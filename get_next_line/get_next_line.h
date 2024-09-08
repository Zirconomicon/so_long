/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:36:05 by moturki           #+#    #+#             */
/*   Updated: 2024/09/02 22:02:24 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		fd;
	int		curlen;
	int		size;
	char	buffer[BUFFER_SIZE];
}				t_list;

char	*get_next_line(int fd);

int		ft_strlen2(const char *str);

char	*ft_strjoin2(char *s1, char s2);

int		init_info(t_list *info, int fd);

char	set_char(t_list *info);

#endif
