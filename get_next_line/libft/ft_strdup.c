/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduric <iduric@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:37:45 by iduric            #+#    #+#             */
/*   Updated: 2024/09/02 22:16:48 by iduric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*z;
	int		i;
	int		j;

	j = 0;
	i = 0;
	z = malloc(sizeof(char) * ft_strlen(s)); //modification pour la fonction map_cpy de test.c dans so_long. il devrait y avoir un + 1
	if (!z)
		return (NULL);
	while (s[i])
		z[j++] = s[i++]; //modification pour la fonction map_cpy de test.c dans so_long. il devrait y avoir un z[j] = '\0';
	return (z);
}
